/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_fwd_do_send_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_fwd_do_send_msg(zmsg_t *msg)

{
  ezb_shortaddr_t dst_addr_00;
  int iVar1;
  zmsg_t *msg_00;
  uint uVar2;
  ushort local_22 [2];
  ezb_shortaddr_t dst_addr;
  
  zmsg_read_le16(msg,2,local_22);
  iVar1 = nwk_is_device_zed();
  if (iVar1 == 0) {
    if (local_22[0] < 0xfff8) {
      iVar1 = nwk_neighbor_table_get_by_short();
      if (((iVar1 != 0) && (uVar2 = *(uint *)(iVar1 + 0xc), (uVar2 & 0x400) == 0)) &&
         (((uVar2 & 0x340) == 0x40 || ((uVar2 & 0x3c0) == 0x140)))) {
        nwk_fwd_mac_data_req(msg,(byte)(uVar2 >> 0xd) & 0x1f,local_22[0],true);
        return;
      }
    }
    else if (local_22[0] == 0xffff) {
      iVar1 = 0;
      while (iVar1 = nwk_child_table_next(iVar1), iVar1 != 0) {
        if ((*(uint *)(iVar1 + 0xc) & 0x7c0) == 0x40) {
          msg_00 = (zmsg_t *)zmsg_clone(msg);
          if (msg_00 == (zmsg_t *)0x0) {
            log_write(2,"nwk_forwarder.c","Failed indirect tx to child: %d",1);
            break;
          }
          uVar2 = *(uint *)(iVar1 + 0xc);
          dst_addr_00 = nwk_neighbor_get_shortaddr(iVar1);
          nwk_fwd_mac_data_req(msg_00,(byte)(uVar2 >> 0xd) & 0x1f,dst_addr_00,true);
        }
      }
    }
  }
  zmsg_queue_enqueue(&s_nwk_fwd,msg);
  tasklet_post(&s_nwk_fwd);
  return;
}

