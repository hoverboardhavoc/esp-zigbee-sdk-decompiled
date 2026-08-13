/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_general_report_attr_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_general_report_attr_handler(int param_1,int param_2)

{
  int iVar1;
  undefined2 *puVar2;
  size_t __size;
  void *pvVar3;
  undefined4 uVar4;
  uint uVar5;
  uint unaff_s3;
  uint unaff_s5;
  undefined2 uVar6;
  ushort local_36;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  undefined2 *puStack_28;
  uint uStack_24;
  
  uStack_34 = 0;
  uStack_30 = 0;
  iStack_2c = 0;
  puStack_28 = (undefined2 *)0x0;
  uStack_24 = 0;
  local_36 = 0;
  if ((((param_1 == 0) || (*(int *)(param_1 + 0x24) == 0)) || (param_2 == 0)) ||
     (*(int *)(param_2 + 0x24) == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0x36a,
                  "zcl_general_report_attr_handler",
                  "packet && packet->payload && rsp && rsp->payload");
_L0:
    uVar6 = 0;
  }
  else {
    unaff_s3 = zmsg_get_length();
    puStack_28 = (undefined2 *)0x0;
    iVar1 = zcl_packet_to_message(&uStack_34,param_1);
    if (iVar1 != 0) {
      uVar5 = 0x80;
      goto _L0;
    }
    unaff_s5 = 0;
    iStack_2c = param_1;
    if ((*(byte *)(param_1 + 0x1a) & 4) == 0) goto _L0;
    uVar6 = *(undefined2 *)(param_1 + 0x1c);
  }
  while (puVar2 = puStack_28, local_36 < unaff_s3) {
    puVar2 = (undefined2 *)calloc(1,0xc);
    *(undefined2 **)(puVar2 + 4) = puStack_28;
    puStack_28 = puVar2;
    af_read_le16(*(undefined4 *)(param_1 + 0x24),&local_36,puVar2);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&local_36,puVar2 + 1);
    if (unaff_s3 < local_36) {
      uVar5 = 0x80;
      goto _L0;
    }
    __size = zcl_packet_read_variable_attr_size
                       (*(undefined4 *)(param_1 + 0x24),*(undefined1 *)(puVar2 + 1));
    pvVar3 = calloc(1,__size);
    *(void **)(puVar2 + 2) = pvVar3;
    zcl_packet_read_variable_attr_value
              (*(undefined4 *)(param_1 + 0x24),&local_36,*(undefined1 *)(puVar2 + 1),pvVar3);
  }
  for (; puVar2 != (undefined2 *)0x0; puVar2 = *(undefined2 **)(puVar2 + 4)) {
    if ((*(byte *)(param_1 + 0x1a) & 8) == 0) {
      uVar4 = 1;
    }
    else {
      uVar4 = 2;
    }
    zcl_reporting_mark_recv_attr_report
              (*(undefined1 *)(param_1 + 0x15),*(undefined2 *)(param_1 + 0x16),uVar4,*puVar2,uVar6);
  }
  uStack_24 = CONCAT31(uStack_24._1_3_,0xfe);
  zcl_core_action_schedule(5,&uStack_34);
  uVar5 = uStack_24 & 0xff;
  if ((uStack_24 & 0xff) == 0xfe) {
    uVar5 = unaff_s5;
  }
_L0:
  while (puStack_28 != (undefined2 *)0x0) {
    puVar2 = *(undefined2 **)(puStack_28 + 4);
    if (*(int *)(puStack_28 + 2) != 0) {
      mm_free();
    }
    mm_free(puStack_28);
    puStack_28 = puVar2;
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar5);
  return;
}

