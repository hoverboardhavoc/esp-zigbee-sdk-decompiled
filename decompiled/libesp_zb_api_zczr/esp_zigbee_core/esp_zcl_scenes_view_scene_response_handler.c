/*
 * Last changed at upstream commit fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * https://github.com/espressif/esp-zigbee-sdk/commit/fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * Upstream date: 2023-08-11 14:15:41 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.0(793f8578)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zcl_scenes_view_scene_response_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zcl_scenes_view_scene_response_handler(undefined4 param_1)

{
  byte bVar1;
  undefined2 *puVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  void *__dest;
  undefined2 *puVar8;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined2 *puStack_38;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined2 *puStack_24;
  
  uVar3 = zb_buf_len_func();
  if (uVar3 < 4) {
_L0:
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar5,"ESP_ZIGBEE_CORE",
                  "esp_zcl_scenes_view_scene_response_handler",0x642);
  }
  else {
    pcVar4 = (char *)zb_buf_begin_func(param_1);
    if (*pcVar4 == '\0') {
      zb_buf_cut_left_func(param_1,(byte)pcVar4[6] + 7);
      pcVar4[6] = '\0';
    }
    else {
      zb_buf_cut_left_func(param_1,4);
      if (pcVar4 == (char *)0x0) goto _L0;
    }
    uStack_2c = CONCAT31(uStack_2c._1_3_,*pcVar4);
    uStack_2c = CONCAT22(*(undefined2 *)(pcVar4 + 1),(undefined2)uStack_2c);
    uStack_28 = CONCAT31(uStack_28._1_3_,pcVar4[3]);
    uStack_28 = CONCAT22(*(undefined2 *)(pcVar4 + 4),(undefined2)uStack_28);
    puStack_24 = (undefined2 *)0x0;
    puVar8 = (undefined2 *)0x0;
    do {
      uVar3 = zb_buf_len_func(param_1);
      puVar7 = puVar8;
      if (uVar3 < 3) {
        puVar6 = (undefined2 *)0x0;
        puVar2 = puStack_24;
      }
      else {
        puVar6 = (undefined2 *)zb_buf_begin_func(param_1);
        bVar1 = *(byte *)(puVar6 + 1);
        uVar3 = zb_buf_len_func(param_1);
        if (uVar3 < bVar1 + 3) {
          puVar6 = (undefined2 *)0x0;
          puVar2 = puStack_24;
        }
        else {
          zb_buf_cut_left_func(param_1,bVar1 + 3);
          puVar2 = puStack_24;
          if (puVar6 != (undefined2 *)0x0) {
            puVar7 = (undefined2 *)malloc(0xc);
            *puVar7 = *puVar6;
            bVar1 = *(byte *)(puVar6 + 1);
            *(byte *)(puVar7 + 1) = bVar1;
            __dest = malloc((uint)bVar1);
            *(void **)(puVar7 + 2) = __dest;
            memcpy(__dest,(void *)((int)puVar6 + 3),(uint)*(byte *)(puVar6 + 1));
            *(undefined4 *)(puVar7 + 4) = 0;
            puVar2 = puVar7;
            if (puVar8 != (undefined2 *)0x0) {
              *(undefined2 **)(puVar8 + 4) = puVar7;
              puVar2 = puStack_24;
            }
          }
        }
      }
      puStack_24 = puVar2;
      puVar8 = puVar7;
    } while (puVar6 != (undefined2 *)0x0);
    if ((pcVar4 != (char *)0x0) && (zcl_scenes_view_scene_resp_cb != (code *)0x0)) {
      local_40 = uStack_2c;
      uStack_3c = uStack_28;
      puStack_38 = puStack_24;
      (*zcl_scenes_view_scene_resp_cb)(&local_40);
      puVar8 = puStack_24;
      while (puVar8 != (undefined2 *)0x0) {
        puVar7 = *(undefined2 **)(puVar8 + 4);
        free(puVar8);
        puVar8 = puVar7;
      }
    }
  }
  return;
}

