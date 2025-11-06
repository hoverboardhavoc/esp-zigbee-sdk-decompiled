/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_touchlink_commissioning.o -> zcl_touchlink_get_group_identifiers_resp_handler
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
  undefined1 auStack_3c [40];
  
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
      esp_log(1,0x10000,"E (%lu) %s: %s(%d): Failed to create get group identifiers message\n",uVar4
              ,0x10000,"zcl_touchlink_get_group_identifiers_resp_handler",0xd5);
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
    iVar3 = esp_zb_core_action_handler_schedule(0x1060,auStack_64);
    puVar2 = puStack_40;
    while (puVar2 != (undefined2 *)0x0) {
      puVar6 = *(undefined2 **)(puVar2 + 2);
      free(puVar2);
      puVar2 = puVar6;
    }
  }
  else {
    uVar4 = esp_log_timestamp();
    esp_log(1,0x10000,
            "E (%lu) %s: touchlink get group_identifiers response command wrong packet size\n",uVar4
            ,0x10000);
    iVar3 = -1;
  }
  free(__ptr);
  return iVar3;
}

