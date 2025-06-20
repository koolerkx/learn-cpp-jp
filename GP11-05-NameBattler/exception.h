/**
 * @file    exception.h
 * @brief   例外クラスの定義
 * @author  KOOLER FAN
 * @date    2025-06-12
 */

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

using Exception = std::exception;

constexpr const char* CHARACTER_LIMIT_EXCEED_EXCEPTION =  "キャラクターの所持数を超えました。";
constexpr const char* HERO_NOT_EXIST_EXCEPTION =  "キャラクターは存在しません。";

constexpr const char* FILE_OUTPUT_FAILED_EXCEPTION = "ファイルの書き出しに失敗しました";
constexpr const char* FILE_INPUT_FAILED_EXCEPTION = "ファイルの読み込みに失敗しました";

namespace exception {
    namespace hero
    {
        class HeroLimitExceedException : public Exception {
        public:
            const char* what() const override
            {
                return CHARACTER_LIMIT_EXCEED_EXCEPTION;
            }
        };
        class HeroNotExistException : public Exception {
        public:
            const char* what() const override
            {
                return HERO_NOT_EXIST_EXCEPTION;
            }
        };
    }

    namespace io
    {
        class FileOutputFailedException : public Exception {
        public:
            const char* what() const override
            {
                return FILE_OUTPUT_FAILED_EXCEPTION;
            }
        };
        class FileInputFailedException : public Exception {
        public:
            const char* what() const override
            {
                return FILE_INPUT_FAILED_EXCEPTION;
            }
        };
    }
}

#endif // EXCEPTION_H