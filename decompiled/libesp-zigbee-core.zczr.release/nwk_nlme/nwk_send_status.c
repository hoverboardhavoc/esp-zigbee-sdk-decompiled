/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_send_status
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_send_status(ezb_shortaddr_t dst_addr,nwk_network_status_cmd_t *cmd)

{
  char cVar1;
  undefined2 in_register_0000202a;
  undefined4 uVar2;
  zmsg_t *msg;
  int iVar3;
  ezb_shortaddr_t eStack_12;
  
  uVar2 = 0x27;
  if (CONCAT22(in_register_0000202a,dst_addr) < 0xfff8) {
    uVar2 = 0x2f;
  }
  msg = (zmsg_t *)zmsg_alloc(uVar2);
  if (msg == (zmsg_t *)0x0) {
    log_write(1,"nwk_nlme.c","Failed to send NwkStatus (%d)");
    return;
  }
  zmsg_set_offset(0);
  uVar2 = nwk_get_short_address();
  nwk_frame_write_hdr(msg,uVar2,CONCAT22(in_register_0000202a,dst_addr),0,1,0);
  iVar3 = core_globals_get();
  cVar1 = *(char *)(iVar3 + 0x9d9);
  *(char *)(iVar3 + 0x9d9) = cVar1 + '\x01';
  eStack_12 = CONCAT11(eStack_12._1_1_,cVar1);
  zmsg_write_bytes(msg,7,1,&eStack_12);
  zmsg_append_u8(msg,'\x03');
  zmsg_append_u8(msg,cmd->status_code);
  eStack_12 = cmd->target_addr;
  zmsg_append_bytes(msg,2,&eStack_12);
  if (cmd->status_code == '\x13') {
    zmsg_append_u8(msg,cmd->command_id);
  }
  nwk_fwd_send_msg(msg);
  return;
}

