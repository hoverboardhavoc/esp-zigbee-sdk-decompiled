/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> zcl_touchlink_get_endpoint_list_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_touchlink_get_endpoint_list_resp_handler(undefined4 param_1)

{
  char cVar1;
  undefined1 *__ptr;
  void *__src;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  undefined2 uStack_6c;
  undefined1 uStack_6a;
  byte bStack_69;
  undefined4 uStack_68;
  undefined4 auStack_64 [8];
  undefined1 uStack_44;
  undefined1 uStack_43;
  char cStack_42;
  undefined2 *puStack_40;
  undefined1 auStack_3c [36];
  
  __ptr = (undefined1 *)malloc(3);
  __src = (void *)zb_buf_get_tail_func(param_1,0x1b);
  memcpy(auStack_3c,__src,0x1b);
  iVar2 = zb_buf_len_func(param_1);
  if (iVar2 == 3) {
    puVar4 = (undefined1 *)zb_buf_begin_func(param_1);
    *__ptr = *puVar4;
    __ptr[1] = puVar4[1];
    __ptr[2] = puVar4[2];
    zb_buf_cut_left_func(param_1,3);
    iVar2 = zb_zcl_basic_message_create(param_1,auStack_64);
    if (iVar2 != 0) {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC22,uVar3,"ESP_ZIGBEE_CORE",
                    "zcl_touchlink_get_endpoint_list_resp_handler",0xb31);
      return iVar2;
    }
    auStack_64[0] = 0;
    uStack_44 = *__ptr;
    uStack_43 = __ptr[1];
    cStack_42 = __ptr[2];
    puStack_40 = (undefined2 *)0x0;
    puVar7 = (undefined2 *)0x0;
    for (cVar1 = cStack_42; cVar1 != '\0'; cVar1 = cVar1 + -1) {
      iVar2 = zb_buf_len_func(param_1);
      if (iVar2 == 8) {
        puVar5 = (undefined2 *)zb_buf_begin_func(param_1);
        uStack_6c = *puVar5;
        uStack_6a = *(undefined1 *)(puVar5 + 1);
        bStack_69 = *(byte *)((int)puVar5 + 3);
        uStack_68 = *(uint *)(puVar5 + 2);
        zb_buf_cut_left_func(param_1,8);
      }
      puVar6 = (undefined2 *)malloc(0x10);
      *puVar6 = uStack_6c;
      *(undefined1 *)(puVar6 + 1) = uStack_6a;
      puVar6[2] = (ushort)((uStack_68 & 0xff) << 8) | (ushort)bStack_69;
      puVar6[3] = (short)(uStack_68 >> 8);
      *(undefined1 *)(puVar6 + 4) = uStack_68._3_1_;
      *(undefined4 *)(puVar6 + 6) = 0;
      puVar5 = puVar6;
      if (puVar7 != (undefined2 *)0x0) {
        *(undefined2 **)(puVar7 + 6) = puVar6;
        puVar5 = puStack_40;
      }
      puStack_40 = puVar5;
      puVar7 = puVar6;
    }
    iVar2 = 0;
    puVar7 = puStack_40;
    if (zb_core_action_cb != (code *)0x0) {
      iVar2 = (*zb_core_action_cb)(0x1061,auStack_64);
      puVar7 = puStack_40;
    }
    while (puVar7 != (undefined2 *)0x0) {
      puVar5 = *(undefined2 **)(puVar7 + 6);
      free(puVar7);
      puVar7 = puVar5;
    }
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar3,"ESP_ZIGBEE_CORE");
    iVar2 = -1;
  }
  free(__ptr);
  return iVar2;
}

