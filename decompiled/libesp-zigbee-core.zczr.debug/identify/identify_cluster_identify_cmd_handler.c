/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> identify.o -> identify_cluster_identify_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void identify_cluster_identify_cmd_handler(int param_1,int param_2)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  ushort uStack_24;
  undefined2 auStack_22 [7];
  
  auStack_22[0] = 0;
  uStack_24 = 0;
  uVar1 = *(undefined1 *)(param_1 + 0x15);
  if (param_1 != 0) {
    if (param_2 == 0) {
      uVar5 = 0xfe;
      goto _L0;
    }
    af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_24,auStack_22);
    uVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar2 < uStack_24) {
      uVar5 = 0x80;
      goto _L0;
    }
    iVar3 = identify_srv_get_attr_desc(uVar1,0);
    iVar4 = identify_srv_get_attr_desc(uVar1,0xeff0);
    if (iVar4 != 0) {
      if (iVar3 == 0) {
        uVar5 = 0x86;
      }
      else if (*(int *)(iVar3 + 8) == 0) {
        uVar5 = 0x86;
      }
      else {
        zcl_message_set_identify_attr_value(uVar1,auStack_22[0]);
        uVar5 = 0;
      }
      goto _L0;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/identify.c",0xfb,
                  "identify_cluster_identify_cmd_handler","identify_timer_ctx_attr_desc");
  }
  uVar5 = 0xfe;
_L0:
  zcl_packet_setup_default_response(param_2,param_1,uVar5);
  return;
}

