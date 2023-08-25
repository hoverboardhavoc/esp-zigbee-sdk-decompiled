/*
 * Last changed at upstream commit 62f83e9155a8a668183e90087b29cd6791297d4c
 * https://github.com/espressif/esp-zigbee-sdk/commit/62f83e9155a8a668183e90087b29cd6791297d4c
 * Upstream date: 2023-08-25 15:56:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.1(b4845e06)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_ieee_address_by_short
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_ieee_address_by_short(void)

{
  int iVar1;
  
  iVar1 = zb_address_ieee_by_short();
  if (iVar1 != 0) {
    iVar1 = 0x105;
  }
  return iVar1;
}

