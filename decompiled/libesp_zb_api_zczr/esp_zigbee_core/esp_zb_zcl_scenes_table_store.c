/*
 * Last changed at upstream commit d50acd5408f73d4459b46a949332bb6e32f97543
 * https://github.com/espressif/esp-zigbee-sdk/commit/d50acd5408f73d4459b46a949332bb6e32f97543
 * Upstream date: 2023-09-08 17:20:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.4(89250ad3)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_scenes_table_store
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_zcl_scenes_table_store(undefined4 param_1,undefined2 param_2,undefined2 *param_3)

{
  uint uVar1;
  undefined2 *puVar2;
  void *__dest;
  int iVar3;
  undefined4 uVar4;
  undefined2 *puVar5;
  
  uVar1 = device_scenes_get_free_entry();
  if (uVar1 < 10) {
    *(undefined2 *)(&DAT_000158e2 + uVar1 * 0xc) = param_2;
    (&DAT_000158e5)[uVar1 * 0xc] = 0;
    if ((&DAT_000158e8)[uVar1 * 3] != 0) {
      device_scene_free_fields();
      (&DAT_000158e8)[uVar1 * 3] = 0;
    }
    puVar5 = (undefined2 *)(&DAT_000158e8)[uVar1 * 3];
    for (; param_3 != (undefined2 *)0x0; param_3 = *(undefined2 **)(param_3 + 4)) {
      puVar2 = (undefined2 *)malloc(0xc);
      (&DAT_000158e5)[uVar1 * 0xc] = (&DAT_000158e5)[uVar1 * 0xc] + *(char *)(param_3 + 1) + '\x03';
      *puVar2 = *param_3;
      *(undefined1 *)(puVar2 + 1) = *(undefined1 *)(param_3 + 1);
      *(undefined4 *)(puVar2 + 4) = 0;
      __dest = malloc((uint)*(byte *)(param_3 + 1));
      *(void **)(puVar2 + 2) = __dest;
      memcpy(__dest,*(void **)(param_3 + 2),(uint)*(byte *)(param_3 + 1));
      if (puVar5 == (undefined2 *)0x0) {
        (&DAT_000158e8)[uVar1 * 3] = puVar2;
      }
      else {
        *(undefined2 **)(puVar5 + 4) = puVar2;
      }
      puVar5 = puVar2;
    }
    iVar3 = zb_nvram_write_dataset(9);
    if (iVar3 != 0) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC49,uVar4,"ESP_ZIGBEE_CORE",
                    "esp_zb_zcl_scenes_table_store",0x343);
      iVar3 = -1;
    }
  }
  else {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar4,"ESP_ZIGBEE_CORE","esp_zb_zcl_scenes_table_store",
                  0x326,param_1);
    iVar3 = -1;
  }
  return iVar3;
}

