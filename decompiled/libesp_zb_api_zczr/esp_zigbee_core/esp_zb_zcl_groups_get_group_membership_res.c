/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_groups_get_group_membership_res
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_groups_get_group_membership_res(undefined4 param_1)

{
  undefined1 *puVar1;
  undefined1 *__ptr;
  uint uVar2;
  int iVar3;
  byte bVar4;
  undefined1 *puVar5;
  
  __ptr = (undefined1 *)malloc(4);
  zb_buf_begin_func(param_1);
  uVar2 = zb_buf_len_func(param_1);
  if (uVar2 < 2) {
    puVar1 = (undefined1 *)0x0;
  }
  else {
    puVar1 = (undefined1 *)zb_buf_begin_func(param_1);
    puVar5 = puVar1;
    if (puVar1 == (undefined1 *)0x0) goto _L0;
    bVar4 = puVar1[1];
    uVar2 = zb_buf_len_func(param_1);
    if (uVar2 < ((bVar4 + 1) * 2 & 0xff)) {
      puVar5 = (undefined1 *)0x0;
      goto _L0;
    }
    for (bVar4 = 0; bVar4 < (byte)puVar1[1]; bVar4 = bVar4 + 1) {
    }
  }
  if (puVar1 == (undefined1 *)0x0) {
    puVar5 = (undefined1 *)0x0;
  }
  else {
    *__ptr = 0;
    __ptr[1] = *puVar1;
    bVar4 = puVar1[1];
    __ptr[2] = bVar4;
    __ptr = (undefined1 *)realloc(__ptr,(bVar4 + 1) * 4);
    puVar5 = *(undefined1 **)(__ptr + 4);
    for (iVar3 = 0; iVar3 < (int)(uint)(byte)__ptr[2]; iVar3 = iVar3 + 1) {
      **(undefined2 **)(__ptr + 4) = *(undefined2 *)(puVar1 + iVar3 * 2 + 2);
      *(int *)(__ptr + 4) = *(int *)(__ptr + 4) + 2;
    }
  }
_L0:
  if (__ptr == (undefined1 *)0x0) {
    (*zcl_get_group_membership_resp_user_cb)(1,0,0,0,zcl_get_group_membership_resp_user_cb);
  }
  else {
    (*zcl_get_group_membership_resp_user_cb)
              (*__ptr,__ptr[1],__ptr[2],puVar5,zcl_get_group_membership_resp_user_cb);
  }
  return;
}

