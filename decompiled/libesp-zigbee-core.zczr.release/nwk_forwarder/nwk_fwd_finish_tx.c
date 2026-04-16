/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_fwd_finish_tx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_fwd_finish_tx(zmsg_t *msg,ezb_err_t error)

{
  uint16_t offset;
  int iVar1;
  uint8_t uStack_1b;
  ushort uStack_1a;
  ushort uStack_18;
  nwk_cmd_id_t cmd_id;
  ezb_shortaddr_t src_addr;
  ezb_shortaddr_t dst_addr;
  uint16_t nwk_fcf;
  nwk_network_status_cmd_t cmd;
  
  uStack_1b = '\0';
  zmsg_read_le16(msg,0,&src_addr);
  zmsg_read_le16(msg,4,&uStack_1a);
  zmsg_read_le16(msg,2,&stack0xffffffe8);
  if ((src_addr & 3) == 1) {
    offset = zmsg_get_offset(msg);
    zmsg_read_u8(msg,offset,&uStack_1b);
  }
  if ((msg->flags & 8) == 0) {
    nwk_handle_data_confirm(msg,error);
    return;
  }
  if (((error != 0) && (uStack_18 < 0xfff8)) && (uStack_1b != '\x03')) {
    if ((src_addr & 0x400) == 0) {
      iVar1 = nwk_route_table_find();
      if (iVar1 == 0) goto _L0;
      if ((*(ushort *)(iVar1 + 0xe) & 0x10) == 0) {
        dst_addr._1_1_ = (undefined1)uStack_18;
        nwk_fcf._0_1_ = (undefined1)(uStack_18 >> 8);
        dst_addr._0_1_ = 2;
      }
      else {
        dst_addr._1_1_ = (undefined1)uStack_1a;
        dst_addr._0_1_ = 0xc;
        nwk_fcf._0_1_ = (undefined1)(uStack_1a >> 8);
        uStack_1a = uStack_18;
      }
    }
    else {
      dst_addr._1_1_ = (undefined1)uStack_18;
      nwk_fcf._0_1_ = (undefined1)(uStack_18 >> 8);
      dst_addr._0_1_ = 0xb;
    }
    nwk_fcf._1_1_ = 0;
    nwk_send_status(uStack_1a,&dst_addr);
    nwk_handle_network_status_local(&dst_addr);
  }
_L0:
  zmsg_free(msg);
  return;
}

