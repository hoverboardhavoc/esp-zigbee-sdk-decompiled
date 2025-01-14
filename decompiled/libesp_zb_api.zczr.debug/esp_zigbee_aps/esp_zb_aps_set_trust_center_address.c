/*
 * Last changed at upstream commit 5becf8b58fd0c6a13fec507be821364ad0ceba39
 * https://github.com/espressif/esp-zigbee-sdk/commit/5becf8b58fd0c6a13fec507be821364ad0ceba39
 * Upstream date: 2025-01-14 03:03:09 +0000
 * Upstream subject: esp-zigbee-sdk: (acad93d1)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_aps.o -> esp_zb_aps_set_trust_center_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_aps_set_trust_center_address(undefined1 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = zb_zdo_joined();
  if (iVar1 == 0) {
    DAT_00011678 = *param_1;
    DAT_00011679 = param_1[1];
    DAT_0001167a = param_1[2];
    DAT_0001167b = param_1[3];
    DAT_0001167c = param_1[4];
    DAT_0001167d = param_1[5];
    DAT_0001167e = param_1[6];
    DAT_0001167f = param_1[7];
    uVar2 = 0;
  }
  else {
    uVar2 = 0x103;
  }
  return uVar2;
}

