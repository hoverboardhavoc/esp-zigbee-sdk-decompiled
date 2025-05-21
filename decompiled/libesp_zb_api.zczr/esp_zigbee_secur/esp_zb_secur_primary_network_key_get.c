/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr -> esp_zigbee_secur.o -> esp_zb_secur_primary_network_key_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 esp_zb_secur_primary_network_key_get(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  iVar1 = zb_zdo_joined();
  if ((iVar1 == 0) || (param_1 == (void *)0x0)) {
    uVar2 = 0x103;
  }
  else {
    puVar3 = &g_zb;
    if ((_DAT_000112c8 & 0x600) == 0x600) {
      puVar3 = (undefined *)
               zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_secur.c"
                         ,0xec);
    }
    memcpy(param_1,puVar3 + (*(uint *)(puVar3 + 0x29c) >> 9 & 3) * 0x11 + 0x24c,0x10);
    uVar2 = 0;
  }
  return uVar2;
}

