/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_secur.o -> esp_zb_secur_primary_network_key_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 esp_zb_secur_primary_network_key_get(void *param_1)

{
  int iVar1;
  
  iVar1 = zb_zdo_joined();
  if (iVar1 != 0) {
    if (param_1 == (void *)0x0) {
      return 0x103;
    }
    if ((_DAT_000112c4 & 0x600) != 0x600) {
      memcpy(param_1,(void *)((_DAT_000112c4 >> 9 & 3) * 0x11 + 0x11274),0x10);
      return 0;
    }
    zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_secur.c",0xec);
  }
  return 0x103;
}

