/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_ias_zone.o -> zb_zcl_ias_zone_cluster_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_zcl_ias_zone_cluster_handler(undefined4 param_1)

{
  bool bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  undefined4 *__ptr;
  uint uVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined4 uVar10;
  uint auStack_48 [8];
  undefined4 uStack_28;
  undefined2 uStack_24;
  
  iVar5 = zb_buf_get_tail_func(0x1b);
  if (((iVar5 == 0) || (*(char *)(iVar5 + 0x14) != '\x01')) ||
     (iVar6 = esp_zb_has_core_action_handler(), iVar6 == 0)) {
_L0:
    iVar6 = 0;
  }
  else {
    bVar4 = true;
    if (*(char *)(iVar5 + 0x13) == '\0') {
      __ptr = (undefined4 *)malloc(6);
      uVar7 = zb_buf_len_func(param_1);
      bVar1 = uVar7 < 6;
      if (!bVar1) {
        puVar8 = (undefined1 *)zb_buf_begin_func(param_1);
        uVar2 = puVar8[5];
        *(undefined1 *)__ptr = *puVar8;
        uVar3 = puVar8[1];
        *(undefined1 *)((int)__ptr + 5) = uVar2;
        *(undefined1 *)((int)__ptr + 1) = uVar3;
        *(undefined1 *)((int)__ptr + 2) = puVar8[2];
        *(undefined1 *)((int)__ptr + 3) = puVar8[3];
        *(undefined1 *)(__ptr + 1) = puVar8[4];
      }
      iVar9 = zb_zcl_basic_message_create(param_1,auStack_48);
      if (iVar9 == 0) {
        uStack_24 = *(undefined2 *)(__ptr + 1);
        uStack_28 = *__ptr;
        uVar10 = 0x1031;
_L0:
        auStack_48[0] = (uint)bVar1;
        iVar9 = esp_zb_core_action_handler_schedule(uVar10,auStack_48);
        free(__ptr);
        bVar4 = iVar9 != 0;
      }
    }
    else {
      if (*(char *)(iVar5 + 0x13) != '\x01') goto _L0;
      __ptr = (undefined4 *)malloc(4);
      uVar7 = zb_buf_len_func(param_1);
      bVar1 = uVar7 < 4;
      if (!bVar1) {
        puVar8 = (undefined1 *)zb_buf_begin_func(param_1);
        *(undefined1 *)__ptr = *puVar8;
        *(undefined1 *)((int)__ptr + 1) = puVar8[1];
        *(undefined1 *)((int)__ptr + 2) = puVar8[2];
        *(undefined1 *)((int)__ptr + 3) = puVar8[3];
      }
      iVar9 = zb_zcl_basic_message_create(param_1,auStack_48);
      if (iVar9 == 0) {
        uStack_28 = *__ptr;
        uVar10 = 0x1030;
        goto _L0;
      }
    }
    zb_zcl_send_default_handler(param_1,iVar5,bVar4);
  }
  return iVar6;
}

