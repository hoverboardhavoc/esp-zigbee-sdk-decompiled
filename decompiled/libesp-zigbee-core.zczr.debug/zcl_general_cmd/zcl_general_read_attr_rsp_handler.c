/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_general_read_attr_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_general_read_attr_rsp_handler(int param_1,int param_2)

{
  void *pvVar1;
  uint uVar2;
  size_t __size;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  uint unaff_s6;
  ushort local_36;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  void *pvStack_28;
  uint uStack_24;
  
  uStack_34 = 0;
  uStack_30 = 0;
  iStack_2c = 0;
  pvStack_28 = (void *)0x0;
  uStack_24 = 0;
  if ((((param_1 == 0) || (*(int *)(param_1 + 0x24) == 0)) || (param_2 == 0)) ||
     (*(int *)(param_2 + 0x24) == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0xad,
                  "zcl_general_read_attr_rsp_handler",
                  "packet && packet->payload && rsp && rsp->payload");
  }
  else {
    unaff_s6 = zcl_packet_to_message(&uStack_34,param_1);
    if (unaff_s6 != 0) {
      uVar2 = 0x80;
      goto _L0;
    }
  }
  uVar5 = *(undefined4 *)(param_1 + 0x24);
  local_36 = 0;
  iStack_2c = param_1;
  uVar2 = zmsg_get_length(uVar5);
  while (local_36 < uVar2) {
    pvVar1 = calloc(1,0xc);
    *(void **)((int)pvVar1 + 8) = pvStack_28;
    pvStack_28 = pvVar1;
    af_read_le16(uVar5,&local_36,pvVar1);
    af_read_le8(uVar5,&local_36,(int)pvVar1 + 2);
    if (uVar2 < local_36) {
      uVar2 = 0x80;
      goto _L0;
    }
    if (*(char *)((int)pvVar1 + 2) == '\0') {
      af_read_le8(uVar5,&local_36,(int)pvVar1 + 3);
      __size = zcl_packet_read_variable_attr_size(uVar5,local_36,*(undefined1 *)((int)pvVar1 + 3));
      if (__size == 0xffff) {
        uVar2 = 0x85;
        goto _L0;
      }
      pvVar3 = calloc(1,__size);
      *(void **)((int)pvVar1 + 4) = pvVar3;
      if ((pvVar3 == (void *)0x0) && (__size != 0)) {
        uVar2 = 0x89;
        goto _L0;
      }
      zcl_packet_read_variable_attr_value(uVar5,&local_36,*(undefined1 *)((int)pvVar1 + 3),pvVar3);
    }
  }
  if ((*(short *)(param_1 + 0x16) != 10) ||
     (iVar4 = zcl_time_server_read_attr_rsp_handler(&uStack_34), uVar2 = unaff_s6, iVar4 == 0)) {
    uStack_24 = CONCAT31(uStack_24._1_3_,0xfe);
    zcl_core_action_schedule(1,&uStack_34);
    uVar2 = uStack_24 & 0xff;
    if ((uStack_24 & 0xff) == 0xfe) {
      uVar2 = unaff_s6;
    }
  }
_L0:
  while (pvStack_28 != (void *)0x0) {
    pvVar1 = *(void **)((int)pvStack_28 + 8);
    if (*(int *)((int)pvStack_28 + 4) != 0) {
      mm_free();
    }
    mm_free(pvStack_28);
    pvStack_28 = pvVar1;
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar2);
  return;
}

