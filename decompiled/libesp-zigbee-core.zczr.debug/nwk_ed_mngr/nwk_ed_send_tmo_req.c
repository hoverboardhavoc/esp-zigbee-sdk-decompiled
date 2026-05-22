/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_ed_mngr.o -> nwk_ed_send_tmo_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_ed_send_tmo_req(void)

{
  uint8_t uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 uStack_15;
  undefined2 auStack_14 [2];
  nwk_ed_tmo_req_cmd_t req;
  
  iVar2 = zmsg_alloc(0x2f);
  if (iVar2 != 0) {
    auStack_14[0] = 0;
    uVar1 = nwk_ed_get_timeout();
    auStack_14[0] = CONCAT11(auStack_14[0]._1_1_,uVar1);
    zmsg_set_offset(iVar2,0);
    uVar3 = nwk_get_short_address();
    uVar4 = nwk_get_parent_shortaddr();
    nwk_frame_write_hdr(iVar2,uVar3,uVar4,1,1,0);
    uStack_15 = 0xb;
    zmsg_append_bytes(iVar2,1,&uStack_15);
    zmsg_append_bytes(iVar2,2,auStack_14);
    nwk_fwd_send_msg_delayed(iVar2,0);
  }
  return (uint)(iVar2 == 0);
}

