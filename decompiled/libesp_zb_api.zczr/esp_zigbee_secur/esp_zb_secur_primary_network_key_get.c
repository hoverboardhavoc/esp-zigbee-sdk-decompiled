/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
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
                         ,0xe9);
    }
    memcpy(param_1,puVar3 + (*(uint *)(puVar3 + 0x29c) >> 9 & 3) * 0x11 + 0x24c,0x10);
    uVar2 = 0;
  }
  return uVar2;
}

