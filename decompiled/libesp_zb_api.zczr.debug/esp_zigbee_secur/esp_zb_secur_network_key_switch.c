/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_secur.o -> esp_zb_secur_network_key_switch
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 esp_zb_secur_network_key_switch(void *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = (_DAT_000112c4 >> 9 & 3) + 1;
  if (param_1 == (void *)0x0) {
    uVar2 = 0x102;
  }
  else {
    iVar1 = (uVar3 - (uVar3 / 3 + ((uint)((ulonglong)uVar3 * 0xaaaaaaab >> 0x20) & 6)) & 0xff) *
            0x11;
    memcpy((void *)(iVar1 + 0x11274),param_1,0x10);
    *(char *)(iVar1 + 0x11284) = (char)param_2;
    secur_nwk_key_switch(param_2);
    uVar2 = 0;
  }
  return uVar2;
}

