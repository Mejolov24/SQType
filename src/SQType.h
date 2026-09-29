#ifndef SQTYPE_H
    #define SQTYPE_H
    #include <stdint.h>
    #include <type_traits>

    template<typename Type, char FractionalBits>
    class SQType{
        public:
        Type raw;
        constexpr SQType() : raw(0) {}
        constexpr SQType(float value) : raw(static_cast<Type>(value * (static_cast<Type>(Type(1) << FractionalBits)))) {}
        static constexpr SQType from_raw(Type raw) {
            SQType result;
            result.raw = raw;
            return result;
        }
        
        constexpr SQType<Type, FractionalBits> operator+(const SQType& other) const{
            return from_raw(raw + other.raw);
            }
        constexpr SQType<Type, FractionalBits> operator-(const SQType& other) const{
            return from_raw(raw - other.raw);
        }

        constexpr SQType<Type, FractionalBits> operator/(const SQType& other) const{
            using WideUType = uint64_t;
            using WideType = int64_t;
            
            bool negative_a = (raw < 0);
            bool negative_b = (other.raw < 0);
            bool negative = (raw < 0) ^ (other.raw < 0);

            // absolute value
            WideUType u_raw = static_cast<WideUType>(negative_a ? -static_cast<WideType>(raw) : raw);
            WideUType u_other = static_cast<WideUType>(negative_b ? -static_cast<WideType>(other.raw)  : other.raw);
            WideType result_raw = static_cast<WideType>((u_raw << FractionalBits) / u_other);
            // restore sign
            Type final_raw = static_cast<Type>(negative ? -static_cast<WideType>(result_raw) : result_raw);

            return from_raw(final_raw);
        }
        constexpr SQType<Type, FractionalBits> operator*(const SQType& other) const{
            using WideUType = uint64_t;
            using WideType = int64_t;
            
            bool negative_a = (raw < 0);
            bool negative_b = (other.raw < 0);
            bool negative = (raw < 0) ^ (other.raw < 0); // aritmethic rules, if signs are different, its negative, otherwise not

            // absolute value
            WideUType u_raw = static_cast<WideUType>(negative_a ? -static_cast<WideType>(raw) : raw);
            WideUType u_other = static_cast<WideUType>(negative_b ? -static_cast<WideType>(other.raw)  : other.raw);
            WideType result_raw =  static_cast<WideType>((u_raw * u_other) >> FractionalBits);
            // restore sign
            Type final_raw = static_cast<Type>(negative ? -static_cast<WideType>(result_raw) : result_raw);

            return from_raw(final_raw);
        }

        template<typename T>
            constexpr operator T() const {
                if constexpr (std::is_integral_v<T>) {
                    return static_cast<T>(raw >> FractionalBits);
                } else {
                    return static_cast<T>(raw) / static_cast<T>(static_cast<Type>(Type(1) << FractionalBits));
                }
            }

    };

    using s8_q7_t = SQType<int8_t, 7>;
    using u8_q7_t = SQType<uint8_t, 7>;
    using s8_q4_t = SQType<int8_t, 4>;
    using u8_q4_t = SQType<uint8_t, 4>;

    using s16_q15_t = SQType<int16_t, 15>;
    using u16_q15_t = SQType<uint16_t, 15>;
    using s16_q12_t = SQType<int16_t, 12>;
    using u16_q12_t = SQType<uint16_t, 12>;
    using s16_q10_t = SQType<int16_t, 10>;
    using u16_q10_t = SQType<uint16_t, 10>;

    using s32_q24_t =SQType<int32_t, 24>;
    using u32_q24_t =SQType<uint32_t, 24>;


    #endif