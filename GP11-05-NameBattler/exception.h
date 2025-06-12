#pragma once
#include <exception>

using Exception = std::exception;

constexpr const char* CHARACTER_LIMIT_EXCEED_EXCEPTION =  "�L�����N�^�[�̏������𒴂��܂����B";

constexpr const char* FILE_OUTPUT_FAILED_EXCEPTION = "�t�@�C���̏����o���Ɏ��s���܂���";
constexpr const char* FILE_INPUT_FAILED_EXCEPTION = "�t�@�C���̓ǂݍ��݂Ɏ��s���܂���";

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
