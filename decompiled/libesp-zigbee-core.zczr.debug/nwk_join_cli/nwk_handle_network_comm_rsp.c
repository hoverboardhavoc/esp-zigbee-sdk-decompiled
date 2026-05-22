/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_cli.o -> nwk_handle_network_comm_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_handle_network_comm_rsp(zmsg_t *msg,nwk_rx_info_t *rx_info)

{
  ezb_shortaddr_t eVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  undefined2 extraout_var;
  ushort uVar5;
  uint error;
  ezb_shortaddr_t eStack_34;
  byte bStack_32;
  nwk_rejoin_rsp_t rsp;
  ezb_extaddr_t dst_extaddr;
  ezb_extaddr_t src_extaddr;
  
  iVar3 = nwk_is_joined();
  if ((iVar3 != 0) || (iVar3 = core_globals_get(), *(char *)(iVar3 + 0xac0) == '\x02')) {
    iVar3 = nwk_secur_get_seclevel();
    uVar5 = (ushort)(iVar3 != 0);
    iVar3 = core_globals_get();
    if (*(char *)(iVar3 + 0xac0) == '\x02') {
      iVar3 = core_globals_get();
      uVar5 = *(ushort *)(iVar3 + 0xad2) & 1;
    }
    if (rx_info->mac_src_addr == rx_info->nwk_src_addr) {
      if (uVar5 != ((msg->flags & 2) != 0)) goto _L0;
      iVar3 = nwk_frame_get_src_extaddr(msg,(undefined1 *)((int)&dst_extaddr.field_0 + 4));
      if ((iVar3 == 0) && (iVar3 = nwk_frame_get_dst_extaddr(msg,&rsp), iVar3 == 0)) {
        piVar4 = (int *)nwk_get_extended_address();
        if ((_rsp == *piVar4) &&
           ((dst_extaddr.field_0.u64._0_4_ == piVar4[1] &&
            (uVar5 = rx_info->nwk_src_addr, eVar1 = nwk_get_parent_shortaddr(),
            (uint)uVar5 == CONCAT22(extraout_var,eVar1))))) {
          eStack_34 = 0;
          bStack_32 = 0;
          sVar2 = zmsg_get_offset(msg);
          zmsg_read_bytes(msg,sVar2 + 1,3,&eStack_34);
          iVar3 = core_globals_get();
          if (*(char *)(iVar3 + 0xac0) == '\0') {
            iVar3 = nwk_is_device_zed();
            if ((iVar3 != 0) && (iVar3 = nwk_is_joined(), iVar3 != 0)) {
              nwk_change_network_address(eStack_34);
            }
          }
          else if (*(char *)(iVar3 + 0xac0) == '\x02') {
            iVar3 = core_globals_get();
            milli_timer_stop(iVar3 + 0xad4);
            iVar3 = core_globals_get();
            if (*(char *)(iVar3 + 0x9ee) == '\0') {
              nwk_pim_stop_fast_poll();
              nwk_pim_stop_poll();
            }
            if (bStack_32 == 0) {
              nwk_mm_set_pib_attr(rx_info->iface_id,0x4a,
                                  (undefined1 *)((int)&dst_extaddr.field_0 + 4));
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
  }
  if (msg == (zmsg_t *)0x0) {
    return;
  }
_L0:
  zmsg_free(msg);
  return;
}

