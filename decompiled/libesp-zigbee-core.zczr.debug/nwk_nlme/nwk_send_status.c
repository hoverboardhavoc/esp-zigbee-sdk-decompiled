/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_nlme.o -> nwk_send_status
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_send_status(uint param_1,char *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined2 uStack_12;
  
  if (param_1 < 0xfff8) {
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
    nwk_frame_write_hdr(iVar2,uVar1,param_1,0,1,0);
    iVar3 = core_globals_get();
    uStack_12._0_1_ = *(char *)(iVar3 + 0x9d9);
    *(char *)(iVar3 + 0x9d9) = (char)uStack_12 + '\x01';
    zmsg_write_bytes(iVar2,7,1,&uStack_12);
    uStack_12._0_1_ = 3;
    zmsg_append_bytes(iVar2,1,&uStack_12);
    uStack_12 = CONCAT11(uStack_12._1_1_,*param_2);
    zmsg_append_bytes(iVar2,1,&uStack_12);
    uStack_12 = *(undefined2 *)(param_2 + 1);
    zmsg_append_bytes(iVar2,2,&uStack_12);
    if (*param_2 == '\x13') {
      uStack_12 = CONCAT11(uStack_12._1_1_,param_2[3]);
      zmsg_append_bytes(iVar2,1,&uStack_12);
      uVar1 = 0;
    }
    else if (*param_2 == '\r') {
      uVar1 = random_add_jitter(0,0x40);
    }
    else {
      uVar1 = 0;
    }
    nwk_fwd_send_msg_delayed(iVar2,uVar1);
  }
  return;
}

