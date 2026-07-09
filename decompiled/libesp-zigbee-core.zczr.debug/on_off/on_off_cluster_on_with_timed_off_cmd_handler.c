/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> on_off.o -> on_off_cluster_on_with_timed_off_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 on_off_cluster_on_with_timed_off_cmd_handler(int param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  char cVar8;
  ushort uVar9;
  ushort uVar10;
  ushort uVar11;
  ushort uStack_28;
  ushort uStack_26;
  byte bStack_23;
  ushort auStack_22 [3];
  
  auStack_22[0] = 0;
  bStack_23 = 0;
  uStack_26 = 0;
  uStack_28 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x1e5,
                  "on_off_cluster_on_with_timed_off_cmd_handler","packet && rsp");
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x1e9,
                  "on_off_cluster_on_with_timed_off_cmd_handler","ep_desc");
  }
  else {
    uVar1 = *(undefined1 *)(param_1 + 0x15);
    uVar2 = *(undefined1 *)(param_1 + 0x20);
    iVar3 = af_get_ep_desc(uVar1);
    if (iVar3 == 0) goto _L0;
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&bStack_23);
    af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_26);
    af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_28);
    uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar4 < auStack_22[0]) {
      return 0x80;
    }
    iVar3 = on_off_srv_get_attr_desc(uVar1,0);
    iVar5 = on_off_srv_get_attr_desc(uVar1,0x4001);
    iVar6 = on_off_srv_get_attr_desc(uVar1,0x4002);
    if (iVar3 != 0) {
      if ((iVar5 != 0) && (iVar6 != 0)) {
        if (iVar3 == 0) {
          cVar8 = '\0';
        }
        else if (*(char **)(iVar3 + 8) == (char *)0x0) {
          cVar8 = '\0';
        }
        else {
          cVar8 = **(char **)(iVar3 + 8);
        }
        if (*(ushort **)(iVar5 + 8) == (ushort *)0x0) {
          uVar10 = 0;
        }
        else {
          uVar10 = **(ushort **)(iVar5 + 8);
        }
        if (*(ushort **)(iVar6 + 8) == (ushort *)0x0) {
          uVar9 = 0;
        }
        else {
          uVar9 = **(ushort **)(iVar6 + 8);
        }
        if (((bStack_23 & 1) != 0) && (cVar8 == '\0')) {
          return 0xfe;
        }
        uVar11 = uStack_28;
        if ((uVar9 == 0) || (cVar8 != '\0')) {
          uVar9 = uStack_26;
          if (uStack_26 < uVar10) {
            uVar9 = uVar10;
          }
          uVar7 = 1;
        }
        else {
          if (uVar9 < uStack_28) {
            uVar11 = uVar9;
          }
          uVar9 = 0;
          uVar7 = 0;
        }
        on_off_process_transition(uVar1,uVar2,uVar7,uVar9,uVar11);
        uVar7 = zcl_packet_setup_default_response(param_2,param_1,0);
        if (uStack_26 == 0xffff) {
          return uVar7;
        }
        if (uStack_28 == 0xffff) {
          return uVar7;
        }
        on_off_timer_start(uVar1,100);
        return uVar7;
      }
      goto _L0;
    }
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x1f5,
                "on_off_cluster_on_with_timed_off_cmd_handler","on_off_attr_desc");
_L0:
  uVar7 = zcl_packet_setup_default_response(param_2,param_1,0x8c);
  return uVar7;
}

