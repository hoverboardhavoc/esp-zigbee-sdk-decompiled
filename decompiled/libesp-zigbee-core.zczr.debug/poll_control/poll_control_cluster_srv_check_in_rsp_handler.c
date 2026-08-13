/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_cluster_srv_check_in_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void poll_control_cluster_srv_check_in_rsp_handler(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  ushort uStack_26;
  ushort uStack_24;
  char acStack_21 [13];
  
  acStack_21[0] = '\0';
  uStack_24 = 0;
  uStack_26 = 0;
  if (param_1 != 0) {
    if (param_2 == 0) {
      uVar3 = 0xfe;
      goto _L0;
    }
    uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_26,acStack_21);
    af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_26,&uStack_24);
    if (uVar1 < uStack_26) {
      uVar3 = 0x80;
      goto _L0;
    }
    iVar2 = poll_control_check_binding
                      (*(undefined1 *)(param_1 + 0x15),*(undefined1 *)(param_1 + 0x14),
                       *(undefined2 *)(param_1 + 2));
    if (iVar2 == 0) {
      uVar3 = 1;
      goto _L0;
    }
    if (acStack_21[0] == '\0') {
      uVar3 = 0;
      goto _L0;
    }
    iVar2 = poll_control_srv_get_attr_desc(*(undefined1 *)(param_1 + 0x15),3);
    if (iVar2 != 0) {
      if (uStack_24 == 0) {
        uStack_24 = **(ushort **)(iVar2 + 8);
      }
      iVar2 = poll_control_srv_get_attr_desc(*(undefined1 *)(param_1 + 0x15),6);
      if ((iVar2 == 0) || (uStack_24 <= **(ushort **)(iVar2 + 8))) {
        poll_control_start_fast_poll(*(undefined1 *)(param_1 + 0x15),(uint)uStack_24 * 0xfa);
        uVar3 = 0;
      }
      else {
        uVar3 = 0x85;
      }
      goto _L0;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/poll_control.c",0x18a,
                  "poll_control_cluster_srv_check_in_rsp_handler",0x102c4);
  }
  uVar3 = 0xfe;
_L0:
  zcl_packet_setup_default_response(param_2,param_1,uVar3);
  return;
}

