/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_fwd_handle_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_fwd_handle_data_confirm(uint8_t iface_id,mac_data_cnf_t *cnf)

{
  zmsg_t *msg;
  uint16_t offset;
  short sVar1;
  undefined3 in_register_00002029;
  int iVar2;
  uint uVar3;
  byte bVar4;
  uint8_t uStack_2c;
  byte bStack_2b;
  uint16_t uStack_2a;
  nwk_cmd_id_t cmd;
  uint8_t rreq_cmd_opt;
  uint16_t fcf;
  ezb_shortaddr_t src_addr;
  ezb_shortaddr_t dst_addr;
  uint16_t fcf_1;
  ezb_shortaddr_t dst_addr_1;
  
  uStack_2a = 0;
  if (cnf->msdu == (zmsg_t *)0x0) {
    return;
  }
  zmsg_read_le16(cnf->msdu,0,&uStack_2a);
  if ((uStack_2a & 0x3c) != 8) {
    return;
  }
  msg = cnf->msdu;
  if ((uStack_2a & 3) == 3) {
    dst_addr = 0;
    uVar3 = 3;
    if ((msg != (zmsg_t *)0x0) && (zmsg_read_le16(msg,0,&dst_addr), (dst_addr & 3) == 3)) {
      uVar3 = 0;
      if (cnf->status != 0) {
        uVar3 = cnf->status | 0x200;
      }
      nwk_handle_intrp_data_sent(msg,uVar3);
      return;
    }
_L0:
    __assert_func(0,0,0,0);
  }
  else {
    uVar3 = 0;
    if (cnf->status != 0) {
      uVar3 = cnf->status | 0x100;
    }
    iVar2 = nwk_process_receive_security(CONCAT31(in_register_00002029,iface_id),msg);
    if (iVar2 != 0) goto _L0;
  }
  zmsg_read_le16(msg,4,(uint16_t *)&cmd);
  zmsg_read_le16(msg,2,&fcf);
  if (((*(uint *)&cnf->status >> 8 & 1) != 0) ||
     ((fcf < 0xfff8 && ((0x10 < uVar3 - 0x1e1 || ((0x10101U >> (uVar3 - 0x1e1 & 0x1f) & 1) == 0)))))
     ) goto _L0;
  uStack_2c = '\0';
  zmsg_read_le16(msg,0,&src_addr);
  zmsg_read_le16(msg,2,&dst_addr);
  if ((src_addr & 3) == 1) {
    offset = zmsg_get_offset(msg);
    zmsg_read_u8(msg,offset,&uStack_2c);
  }
  if ((uStack_2c == '\b') || (uStack_2c == '\r')) goto _L0;
  if (uStack_2c == '\x01') {
    sVar1 = zmsg_get_offset(msg);
    zmsg_read_u8(msg,sVar1 + 1,&bStack_2b);
    if ((bStack_2b & 0x18) != 0) goto _L0;
    iVar2 = 0xfe;
    if ((msg->flags & 8) == 0) goto _L0;
    iVar2 = random_add_jitter(2,0x7e);
    bVar4 = 2;
  }
  else {
    iVar2 = 0x32;
    if (dst_addr < 0xfff8) {
_L0:
      bVar4 = 3;
    }
    else {
      iVar2 = core_globals_get();
      bVar4 = *(byte *)(iVar2 + 0x9d8);
      iVar2 = random_add_jitter(0,0x40);
    }
  }
  if (msg->nwk_retries < bVar4) {
    msg->nwk_retries = msg->nwk_retries + 1;
    if (iVar2 != 0) {
      zmsg_tmque_enqueue(&s_nwk_fwd,msg);
      return;
    }
    nwk_fwd_do_send_msg(msg);
    return;
  }
_L0:
  if (((*(uint *)&cnf->status >> 8 & 1) == 0) || (fcf < 0xfff8)) {
    nwk_fwd_finish_tx(msg,uVar3);
  }
  else {
    zmsg_free(msg);
  }
  return;
}

