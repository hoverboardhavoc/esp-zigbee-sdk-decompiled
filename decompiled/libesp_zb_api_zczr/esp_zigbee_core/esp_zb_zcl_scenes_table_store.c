/*
 * Last changed at upstream commit 1f6b611e278a00f885edde9cb38294c3c08373a5
 * https://github.com/espressif/esp-zigbee-sdk/commit/1f6b611e278a00f885edde9cb38294c3c08373a5
 * Upstream date: 2023-08-01 20:17:41 +0800
 * Upstream subject: esp-zigbee-sdk: fix zigbee zcl scenes extension field implementation
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_scenes_table_store
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_scenes_table_store(undefined4 param_1,undefined2 param_2,undefined2 *param_3)

{
  uint uVar1;
  undefined2 *puVar2;
  void *__dest;
  undefined4 uVar3;
  undefined2 *puVar4;
  
  uVar1 = device_scenes_get_free_entry();
  if (uVar1 < 10) {
    *(undefined2 *)(&DAT_000137a6 + uVar1 * 0xc) = param_2;
    (&DAT_000137a9)[uVar1 * 0xc] = 0;
    if ((&DAT_000137ac)[uVar1 * 3] != 0) {
      device_scene_free_fields();
      (&DAT_000137ac)[uVar1 * 3] = 0;
    }
    puVar4 = (undefined2 *)(&DAT_000137ac)[uVar1 * 3];
    for (; param_3 != (undefined2 *)0x0; param_3 = *(undefined2 **)(param_3 + 4)) {
      puVar2 = (undefined2 *)malloc(0xc);
      (&DAT_000137a9)[uVar1 * 0xc] = (&DAT_000137a9)[uVar1 * 0xc] + *(char *)(param_3 + 1) + '\x03';
      *puVar2 = *param_3;
      *(undefined1 *)(puVar2 + 1) = *(undefined1 *)(param_3 + 1);
      *(undefined4 *)(puVar2 + 4) = 0;
      __dest = malloc((uint)*(byte *)(param_3 + 1));
      *(void **)(puVar2 + 2) = __dest;
      memcpy(__dest,*(void **)(param_3 + 2),(uint)*(byte *)(param_3 + 1));
      if (puVar4 == (undefined2 *)0x0) {
        (&DAT_000137ac)[uVar1 * 3] = puVar2;
      }
      else {
        *(undefined2 **)(puVar4 + 4) = puVar2;
      }
      puVar4 = puVar2;
    }
    uVar3 = 0;
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC33,uVar3,"ESP_ZIGBEE_CORE","esp_zb_zcl_scenes_table_store"
                  ,0x280,param_1);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

