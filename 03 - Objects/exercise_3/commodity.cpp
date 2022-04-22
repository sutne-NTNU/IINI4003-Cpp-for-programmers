#include "commodity.hpp"

// sales tax of 25 percent
const double sales_tax = 1.25;

Commodity::Commodity(const std::string &name_, int id_, double price_) : name(name_), id(id_), price(price_) {}

std::string Commodity::get_name() const {
  return name;
}

int Commodity::get_id() const {
  return id;
}

double Commodity::get_price() const {
  return price;
}

double Commodity::get_price(double quantity_) const {
  return price * quantity_;
}

void Commodity::set_price(double price_) {
  Commodity::price = price_;
}

double Commodity::get_price_with_sales_tax(double quantity_) const {
  return price * quantity_ * sales_tax;
}
