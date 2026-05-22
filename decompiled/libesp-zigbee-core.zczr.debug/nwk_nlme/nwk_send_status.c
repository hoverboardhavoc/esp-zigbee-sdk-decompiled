/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_nlme.o -> nwk_send_status
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_send_status(ezb_shortaddr_t dst_addr,nwk_network_status_cmd_t *cmd)

{
  undefined2 in_register_0000202a;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  ezb_shortaddr_t eStack_12;
  
  if (CONCAT22(in_register_0000202a,dst_addr) < 0xfff8) {
    uVar1 = 0x2f;
  }
  else {
    uVar1 = 0x27;
  }
  iVar2 = zmsg_alloc(uVar1);
  if (iVar2 == 0) {
    log_write(1,"nwk_nlme.c","Failed to send NwkStatus (%d)");
  }
  else {
    zmsg_set_offset(0);
    uVar1 = nwk_get_short_address();
    nwk_frame_write_hdr(iVar2,uVar1,CONCAT22(in_register_0000202a,dst_addr),0,1,0);
    iVar3 = core_globals_get();
    eStack_12._0_1_ = *(char *)(iVar3 + 0x9d9);
    *(char *)(iVar3 + 0x9d9) = (char)eStack_12 + '\x01';
    zmsg_write_bytes(iVar2,7,1,&eStack_12);
    eStack_12._0_1_ = 3;
    zmsg_append_bytes(iVar2,1,&eStack_12);
    eStack_12 = CONCAT11(eStack_12._1_1_,cmd->status_code);
    zmsg_append_bytes(iVar2,1,&eStack_12);
    eStack_12 = cmd->target_addr;
    zmsg_append_bytes(iVar2,2,&eStack_12);
    if (cmd->status_code == '\x13') {
      eStack_12 = CONCAT11(eStack_12._1_1_,cmd->command_id);
      zmsg_append_bytes(iVar2,1,&eStack_12);
      uVar1 = 0;
    }
    else if (cmd->status_code == '\r') {
      uVar1 = random_add_jitter(0,0x40);
    }
    else {
      uVar1 = 0;
    }
    nwk_fwd_send_msg_delayed(iVar2,uVar1);
  }
  return;
}

