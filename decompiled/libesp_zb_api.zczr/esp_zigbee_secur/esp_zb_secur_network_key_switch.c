/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libesp_zb_api.zczr -> esp_zigbee_secur.o -> esp_zb_secur_network_key_switch
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 esp_zb_secur_network_key_switch(void *param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 != (void *)0x0) {
    iVar1 = (((_DAT_000112c8 >> 9 & 3) + 1) % 3) * 0x11;
    memcpy((void *)(iVar1 + 0x11278),param_1,0x10);
    *(char *)(iVar1 + 0x11288) = (char)param_2;
    secur_nwk_key_switch(param_2);
    return 0;
  }
  return 0x102;
}

