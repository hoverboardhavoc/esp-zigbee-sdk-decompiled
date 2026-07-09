/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_send_status
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_send_status(uint param_1,char *param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined2 uStack_12;
  
  uVar2 = 0x27;
  if (param_1 < 0xfff8) {
    uVar2 = 0x2f;
  }
  iVar3 = zmsg_alloc(uVar2);
  if (iVar3 == 0) {
    log_write(1,"nwk_nlme.c","Failed to send NwkStatus (%d)");
    return;
  }
  zmsg_set_offset(0);
  uVar2 = nwk_get_short_address();
  nwk_frame_write_hdr(iVar3,uVar2,param_1,0,1,0);
  iVar4 = core_globals_get();
  cVar1 = *(char *)(iVar4 + 0x9d9);
  *(char *)(iVar4 + 0x9d9) = cVar1 + '\x01';
  uStack_12 = CONCAT11(uStack_12._1_1_,cVar1);
  zmsg_write_bytes(iVar3,7,1,&uStack_12);
  zmsg_append_u8_isra_0(iVar3,3);
  zmsg_append_u8_isra_0(iVar3,*param_2);
  uStack_12 = *(undefined2 *)(param_2 + 1);
  zmsg_append_bytes(iVar3,2,&uStack_12);
  if (*param_2 == '\x13') {
    zmsg_append_u8_isra_0(iVar3,param_2[3]);
  }
  else if (*param_2 == '\r') {
    uVar2 = random_add_jitter(0,0x40);
    goto _L0;
  }
  uVar2 = 0;
_L0:
  nwk_fwd_send_msg_delayed(iVar3,uVar2);
  return;
}

