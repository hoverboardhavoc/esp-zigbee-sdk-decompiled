/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_send_msg_loopback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: aps_hdr */
/* WARNING: Unknown calling convention */

void aps_send_msg_loopback(aps_addr_t *addr,zmsg_t *msg)

{
  ezb_shortaddr_t eVar1;
  zmsg_t *msg_00;
  undefined1 auStack_24 [4];
  aps_header_t aps_hdr;
  
  eVar1 = addr->grp_addr;
  msg_00 = (zmsg_t *)zmsg_clone(msg);
  if (msg_00 != (zmsg_t *)0x0) {
    aps_hdr.addr_info.cluster_id = 0;
    aps_hdr.addr_info.profile_id = 0;
    aps_hdr.fcf = '\0';
    aps_hdr.aps_cntr = '\0';
    auStack_24._0_2_ = addr->src_addr;
    auStack_24._2_2_ = addr->dst_addr;
    aps_hdr.addr_info._0_4_ = *(undefined4 *)&addr->grp_addr;
    aps_hdr.addr_info._4_4_ = *(undefined4 *)&addr->cluster_id;
    aps_handle_data((aps_header_t *)auStack_24,msg_00);
  }
  if (eVar1 == 0) {
    aps_send_confirm(msg,(uint)(msg_00 == (zmsg_t *)0x0));
  }
  return;
}

