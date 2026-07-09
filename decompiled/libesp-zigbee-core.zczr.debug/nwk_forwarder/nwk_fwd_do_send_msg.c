/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_do_send_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_fwd_do_send_msg(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  ushort auStack_22 [7];
  
  zmsg_read_bytes(2,auStack_22);
  iVar1 = nwk_is_device_zed();
  if (iVar1 == 0) {
    if (auStack_22[0] < 0xfff8) {
      iVar1 = nwk_neighbor_table_get_by_short();
      if (((iVar1 != 0) && ((*(uint *)(iVar1 + 0xc) & 0x400) == 0)) &&
         ((uVar4 = *(uint *)(iVar1 + 0xc) & 0x3c0, uVar4 == 0x40 ||
          ((uVar4 == 0x140 || (uVar4 == 0xc0)))))) {
        nwk_fwd_mac_data_req(param_1,*(uint *)(iVar1 + 0xc) >> 0xd & 0x1f,auStack_22[0],1);
        return;
      }
    }
    else if (auStack_22[0] == 0xffff) {
      iVar1 = 0;
      while (iVar1 = nwk_child_table_next(iVar1), iVar1 != 0) {
        if ((*(uint *)(iVar1 + 0xc) & 0x7c0) == 0x40) {
          iVar3 = zmsg_clone(param_1);
          if (iVar3 == 0) {
            log_write(2,"nwk_forwarder.c","Failed indirect tx to child: %d",1);
            break;
          }
          uVar4 = *(uint *)(iVar1 + 0xc);
          uVar2 = nwk_neighbor_get_shortaddr(iVar1);
          nwk_fwd_mac_data_req(iVar3,uVar4 >> 0xd & 0x1f,uVar2,1);
        }
      }
    }
  }
  zmsg_queue_enqueue(&s_nwk_fwd,param_1);
  tasklet_post(&s_nwk_fwd);
  return;
}

