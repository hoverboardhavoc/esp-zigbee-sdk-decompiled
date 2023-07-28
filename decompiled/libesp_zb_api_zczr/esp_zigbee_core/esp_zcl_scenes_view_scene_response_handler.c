/*
 * Last changed at upstream commit 992d2f5b99d09ff49d4d820bb9dc59b1d40be6d4
 * https://github.com/espressif/esp-zigbee-sdk/commit/992d2f5b99d09ff49d4d820bb9dc59b1d40be6d4
 * Upstream date: 2023-07-28 17:48:58 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.7.2(e1472baa)
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
  undefined2 *puVar4;
  undefined2 *puVar5;
  void *__dest;
  undefined2 *puVar6;
  char *pcVar7;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined2 *puStack_38;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined2 *puStack_24;
  
  uVar3 = zb_buf_len_func();
  if (uVar3 < 4) {
    pcVar7 = (char *)0x0;
  }
  else {
    pcVar7 = (char *)zb_buf_begin_func(param_1);
    if (*pcVar7 == '\0') {
      zb_buf_cut_left_func(param_1,(byte)pcVar7[6] + 7);
      pcVar7[6] = '\0';
    }
    else {
      zb_buf_cut_left_func(param_1,4);
    }
  }
  uStack_2c = CONCAT31(uStack_2c._1_3_,*pcVar7);
  uStack_2c = CONCAT22(*(undefined2 *)(pcVar7 + 1),(undefined2)uStack_2c);
  uStack_28 = CONCAT31(uStack_28._1_3_,pcVar7[3]);
  uStack_28 = CONCAT22(*(undefined2 *)(pcVar7 + 4),(undefined2)uStack_28);
  puStack_24 = (undefined2 *)0x0;
  puVar6 = (undefined2 *)0x0;
  do {
    uVar3 = zb_buf_len_func(param_1);
    puVar5 = puVar6;
    if (uVar3 < 3) {
      puVar4 = (undefined2 *)0x0;
      puVar2 = puStack_24;
    }
    else {
      puVar4 = (undefined2 *)zb_buf_begin_func(param_1);
      bVar1 = *(byte *)(puVar4 + 1);
      uVar3 = zb_buf_len_func(param_1);
      if (uVar3 < bVar1 + 3) {
        puVar4 = (undefined2 *)0x0;
        puVar2 = puStack_24;
      }
      else {
        zb_buf_cut_left_func(param_1,bVar1 + 3);
        puVar2 = puStack_24;
        if (puVar4 != (undefined2 *)0x0) {
          puVar5 = (undefined2 *)malloc(0xc);
          *puVar5 = *puVar4;
          bVar1 = *(byte *)(puVar4 + 1);
          *(byte *)(puVar5 + 1) = bVar1;
          __dest = malloc((uint)bVar1);
          *(void **)(puVar5 + 2) = __dest;
          memcpy(__dest,(void *)((int)puVar4 + 3),(uint)*(byte *)(puVar4 + 1));
          *(undefined4 *)(puVar5 + 4) = 0;
          puVar2 = puVar5;
          if (puVar6 != (undefined2 *)0x0) {
            *(undefined2 **)(puVar6 + 4) = puVar5;
            puVar2 = puStack_24;
          }
        }
      }
    }
    puStack_24 = puVar2;
    puVar6 = puVar5;
  } while (puVar4 != (undefined2 *)0x0);
  if ((pcVar7 != (char *)0x0) && (zcl_scenes_view_scene_resp_cb != (code *)0x0)) {
    local_40 = uStack_2c;
    uStack_3c = uStack_28;
    puStack_38 = puStack_24;
    (*zcl_scenes_view_scene_resp_cb)(&local_40);
    puVar6 = puStack_24;
    while (puVar6 != (undefined2 *)0x0) {
      puVar5 = *(undefined2 **)(puVar6 + 4);
      free(puVar6);
      puVar6 = puVar5;
    }
  }
  return;
}

