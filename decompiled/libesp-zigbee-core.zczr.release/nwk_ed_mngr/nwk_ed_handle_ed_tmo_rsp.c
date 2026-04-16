/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_ed_mngr.o -> nwk_ed_handle_ed_tmo_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_ed_handle_ed_tmo_rsp(zmsg_t *msg,nwk_rx_info_t *rx_info)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  char cStack_14;
  undefined1 uStack_13;
  nwk_ed_tmo_rsp_cmd_t rsp;
  
  iVar3 = nwk_is_device_zed();
  if ((iVar3 == 0) || (iVar3 = nwk_is_joined(), iVar3 == 0)) {
    if (msg == (zmsg_t *)0x0) {
      return;
    }
  }
  else {
    iVar3 = nwk_secur_get_seclevel();
    if (((ushort)(iVar3 != 0) == (msg->flags >> 1 & 1)) &&
       (uVar1 = rx_info->mac_src_addr, uVar4 = nwk_get_parent_shortaddr(), uVar1 == uVar4)) {
      nwk_pim_stop_fast_poll();
      sVar2 = zmsg_get_offset(msg);
      zmsg_read_bytes(msg,sVar2 + 1,2,&cStack_14);
      if (cStack_14 == '\0') {
        iVar3 = core_globals_get();
        *(undefined1 *)(iVar3 + 0xa28) = uStack_13;
        iVar3 = core_globals_get();
        *(byte *)(iVar3 + 0xaf8) = *(byte *)(iVar3 + 0xaf8) | 0x40;
      }
      nwk_ed_process_keepalive_result(cStack_14 == '\0');
    }
  }
  zmsg_free(msg);
  return;
}

