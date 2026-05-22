/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_handle_leave_sent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: cnf */
/* WARNING: Unknown calling convention */

void nwk_handle_leave_sent(zmsg_t *msg,ezb_err_t error)

{
  byte bVar1;
  uint uVar2;
  short sVar3;
  int iVar4;
  byte bStack_21;
  undefined1 auStack_20 [3];
  uint8_t cmd_opt;
  nwk_leave_cnf_t cnf;
  
  bStack_21 = 0;
  sVar3 = zmsg_get_offset();
  zmsg_read_bytes(msg,sVar3 + 1,1,&bStack_21);
  bVar1 = bStack_21;
  uVar2 = (uint)bStack_21;
  if ((bStack_21 & 0x40) == 0) {
    iVar4 = core_globals_get();
    if (*(char *)(iVar4 + 0xac0) != '\x04') {
      __assert_func(0,0,0,0);
    }
    nwk_do_leave_continue(error,(_Bool)(bStack_21 >> 5 & 1),(_Bool)(bStack_21 >> 7));
  }
  else {
    if (error == 0x1f0) {
      error = 0;
    }
    memset(auStack_20 + 1,0,0xd);
    cnf.field_1._6_1_ = (byte)((uVar2 & 1) << 1) | bVar1 >> 5 & 1;
    auStack_20[0] = (nwk_status_t)error;
    iVar4 = nwk_frame_get_dst_extaddr(msg,&cnf);
    if (iVar4 == 0) {
      zmsg_read_bytes(msg,2,auStack_20 + 2);
      nwk_handle_device_leave((nwk_leave_ind_t *)(auStack_20 + 2));
      nwk_leave_confirm((nwk_leave_cnf_t *)auStack_20);
    }
  }
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return;
}

