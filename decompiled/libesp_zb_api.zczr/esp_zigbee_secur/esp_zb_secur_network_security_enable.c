/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_secur.o -> esp_zb_secur_network_security_enable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_secur_network_security_enable(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = zb_zdo_joined();
  if (iVar1 == 0) {
    g_zb = (-(param_1 == 0) & 0xfbU) + 5;
    uVar2 = 0;
  }
  else {
    uVar2 = 0x103;
  }
  return uVar2;
}

