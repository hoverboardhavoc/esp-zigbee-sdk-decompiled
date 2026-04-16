/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_cli.o -> nwk_handle_network_comm_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_handle_network_comm_rsp(zmsg_t *msg,nwk_rx_info_t *rx_info)

{
  ushort uVar1;
  uint error;
  ezb_shortaddr_t eVar2;
  short sVar3;
  int iVar4;
  int *piVar5;
  undefined2 extraout_var;
  ezb_shortaddr_t eStack_34;
  byte bStack_32;
  nwk_rejoin_rsp_t rsp;
  ezb_extaddr_t src_extaddr;
  ezb_extaddr_t dst_extaddr;
  
  iVar4 = nwk_secur_get_seclevel();
  uVar1 = (ushort)(iVar4 != 0);
  iVar4 = core_globals_get();
  if (*(char *)(iVar4 + 0xac0) == '\x02') {
    iVar4 = core_globals_get();
    uVar1 = *(ushort *)(iVar4 + 0xad2) & 1;
  }
  if (rx_info->mac_src_addr == rx_info->nwk_src_addr) {
    if (((uVar1 == (msg->flags >> 1 & 1)) &&
        (iVar4 = nwk_frame_get_src_extaddr(msg,&rsp), iVar4 == 0)) &&
       (iVar4 = nwk_frame_get_dst_extaddr(msg,(undefined1 *)((int)&src_extaddr.field_0 + 4)),
       iVar4 == 0)) {
      piVar5 = (int *)nwk_get_extended_address();
      if (((src_extaddr.field_0.u64._4_4_ == *piVar5) &&
          (dst_extaddr.field_0.u64._0_4_ == piVar5[1])) &&
         (uVar1 = rx_info->nwk_src_addr, eVar2 = nwk_get_parent_shortaddr(),
         (uint)uVar1 == CONCAT22(extraout_var,eVar2))) {
        eStack_34 = 0;
        bStack_32 = 0;
        sVar3 = zmsg_get_offset(msg);
        zmsg_read_bytes(msg,sVar3 + 1,3,&eStack_34);
        iVar4 = core_globals_get();
        if (*(char *)(iVar4 + 0xac0) == '\0') {
          iVar4 = nwk_is_device_zed();
          if ((iVar4 != 0) && (iVar4 = nwk_is_joined(), iVar4 != 0)) {
            nwk_change_network_address(eStack_34);
          }
        }
        else if (*(char *)(iVar4 + 0xac0) == '\x02') {
          iVar4 = core_globals_get();
          milli_timer_stop(iVar4 + 0xad4);
          iVar4 = core_globals_get();
          if (*(char *)(iVar4 + 0x9ee) == '\0') {
            nwk_pim_stop_fast_poll();
            nwk_pim_stop_poll();
          }
          if (bStack_32 == 0) {
            nwk_mm_set_pib_attr(0xff,0x4a,&rsp);
          }
          error = 0;
          if (bStack_32 != 0) {
            error = bStack_32 | 0x200;
          }
          nwk_do_attach_done(error,eStack_34);
        }
      }
    }
  }
  else if (msg == (zmsg_t *)0x0) {
    return;
  }
  zmsg_free(msg);
  return;
}

