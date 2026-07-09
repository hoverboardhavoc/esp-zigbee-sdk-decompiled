/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_cluster_srv_check_in_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void poll_control_cluster_srv_check_in_rsp_handler(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  short sStack_16;
  ushort uStack_14;
  char cStack_11;
  
  cStack_11 = '\0';
  uStack_14 = 0;
  sStack_16 = 0;
  if (param_1 != 0) {
    if (param_2 == 0) {
      uVar2 = 0xfe;
      goto _L0;
    }
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&sStack_16,&cStack_11);
    af_read_le16(*(undefined4 *)(param_1 + 0x24),&sStack_16,&uStack_14);
    if (sStack_16 != 0) {
      uVar2 = 0x80;
      goto _L0;
    }
    iVar1 = poll_control_source_is_exist_in_bind_table
                      (*(undefined1 *)(param_1 + 0x14),*(undefined2 *)(param_1 + 2));
    if (iVar1 == 0) {
      uVar2 = 1;
      goto _L0;
    }
    if (cStack_11 == '\0') {
      uVar2 = 0;
      goto _L0;
    }
    iVar1 = poll_control_srv_get_attr_desc(*(undefined1 *)(param_1 + 0x15),3);
    if (iVar1 != 0) {
      if (uStack_14 == 0) {
        uStack_14 = **(ushort **)(iVar1 + 8);
      }
      iVar1 = poll_control_srv_get_attr_desc(*(undefined1 *)(param_1 + 0x15),6);
      if ((iVar1 == 0) || (uStack_14 <= **(ushort **)(iVar1 + 8))) {
        poll_control_start_fast_poll(*(undefined1 *)(param_1 + 0x15),(uint)uStack_14 * 0xfa);
        uVar2 = 0;
      }
      else {
        uVar2 = 0x85;
      }
      goto _L0;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/poll_control.c",0x180,
                  "poll_control_cluster_srv_check_in_rsp_handler",0x1026c);
  }
  uVar2 = 0xfe;
_L0:
  zcl_packet_setup_default_response(param_2,param_1,uVar2);
  return;
}

