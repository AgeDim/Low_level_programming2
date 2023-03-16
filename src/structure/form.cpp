#include "form.h"

form::form(crud crud_operation) {
    this->crud_operation = crud_operation;
    this->tree = nullptr;
}
