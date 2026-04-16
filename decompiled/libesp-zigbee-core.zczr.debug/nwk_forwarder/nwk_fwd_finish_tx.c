/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_finish_tx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_fwd_finish_tx(zmsg_t *msg,ezb_err_t error)

{
  undefined4 uVar1;
  int iVar2;
  char cStack_17;
  ushort uStack_16;
  ezb_shortaddr_t eStack_14;
  nwk_cmd_id_t cmd_id;
  uint16_t nwk_fcf;
  ezb_shortaddr_t dst_addr;
  ezb_shortaddr_t src_addr;
  
  cStack_17 = '\0';
  zmsg_read_bytes(0,2,&uStack_16);
  zmsg_read_bytes(msg,4,2,&nwk_fcf);
  zmsg_read_bytes(msg,2,&stack0xffffffec);
  if ((uStack_16 & 3) == 1) {
    uVar1 = zmsg_get_offset(msg);
    zmsg_read_bytes(msg,uVar1,1,&cStack_17);
  }
  if ((msg->flags & 8) == 0) {
    nwk_handle_data_confirm(msg,error);
  }
  else {
    if (error != 0) {
      if ((eStack_14 < 0xfff8) && (cStack_17 != '\x03')) {
        if ((uStack_16 & 0x400) == 0) {
          iVar2 = nwk_route_table_find(eStack_14);
          if (iVar2 != 0) {
            if ((*(ushort *)(iVar2 + 0xe) & 0x10) == 0) {
              nwk_raise_link_failure(nwk_fcf,eStack_14);
            }
            else {
              nwk_raise_mto_route_failure(nwk_fcf,eStack_14);
            }
          }
        }
        else {
          nwk_raise_source_route_failure(nwk_fcf,eStack_14);
        }
      }
    }
    if (msg != (zmsg_t *)0x0) {
      zmsg_free(msg);
    }
  }
  return;
}

