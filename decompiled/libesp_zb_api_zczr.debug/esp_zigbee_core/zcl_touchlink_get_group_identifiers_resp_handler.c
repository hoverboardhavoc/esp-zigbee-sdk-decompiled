/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> zcl_touchlink_get_group_identifiers_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_touchlink_get_group_identifiers_resp_handler(undefined4 param_1)

{
  char cVar1;
  undefined2 *puVar2;
  undefined1 *__ptr;
  void *__src;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  undefined2 uStack_68;
  undefined4 auStack_64 [8];
  undefined1 uStack_44;
  undefined1 uStack_43;
  char cStack_42;
  undefined2 *puStack_40;
  undefined1 auStack_3c [36];
  
  __ptr = (undefined1 *)malloc(3);
  __src = (void *)zb_buf_get_tail_func(param_1,0x1b);
  memcpy(auStack_3c,__src,0x1b);
  iVar3 = zb_buf_len_func(param_1);
  if (iVar3 == 3) {
    puVar5 = (undefined1 *)zb_buf_begin_func(param_1);
    *__ptr = *puVar5;
    __ptr[1] = puVar5[1];
    __ptr[2] = puVar5[2];
    zb_buf_cut_left_func(param_1,3);
    iVar3 = zb_zcl_basic_message_create(param_1,auStack_64);
    if (iVar3 != 0) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC20,uVar4,"ESP_ZIGBEE_CORE",
                    "zcl_touchlink_get_group_identifiers_resp_handler",0xaf6);
      return iVar3;
    }
    auStack_64[0] = 0;
    uStack_44 = *__ptr;
    uStack_43 = __ptr[1];
    cStack_42 = __ptr[2];
    puStack_40 = (undefined2 *)0x0;
    puVar2 = (undefined2 *)0x0;
    for (cVar1 = cStack_42; cVar1 != '\0'; cVar1 = cVar1 + -1) {
      iVar3 = zb_buf_len_func(param_1);
      if (iVar3 == 3) {
        puVar6 = (undefined2 *)zb_buf_begin_func(param_1);
        uStack_68 = *puVar6;
        zb_buf_cut_left_func(param_1,3);
      }
      puVar7 = (undefined2 *)malloc(8);
      *puVar7 = uStack_68;
      *(char *)(puVar7 + 1) = (char)uStack_68;
      *(undefined4 *)(puVar7 + 2) = 0;
      puVar6 = puVar7;
      if (puVar2 != (undefined2 *)0x0) {
        *(undefined2 **)(puVar2 + 2) = puVar7;
        puVar6 = puStack_40;
      }
      puStack_40 = puVar6;
      puVar2 = puVar7;
    }
    iVar3 = 0;
    puVar2 = puStack_40;
    if (zb_core_action_cb != (code *)0x0) {
      iVar3 = (*zb_core_action_cb)(0x1060,auStack_64);
      puVar2 = puStack_40;
    }
    while (puVar2 != (undefined2 *)0x0) {
      puVar6 = *(undefined2 **)(puVar2 + 2);
      free(puVar2);
      puVar2 = puVar6;
    }
  }
  else {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC19,uVar4,"ESP_ZIGBEE_CORE");
    iVar3 = -1;
  }
  free(__ptr);
  return iVar3;
}

