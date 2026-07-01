/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> aps_commands.o -> apsme_switch_key_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t apsme_switch_key_request(apsme_switch_key_req_t *req)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  zmsg_t *msg;
  ezb_err_t eVar4;
  
  eVar4 = 2;
  if (req != (apsme_switch_key_req_t *)0x0) {
    uVar1 = *(uint *)&(req->dst_address).field_0;
    uVar2 = *(uint *)((int)&(req->dst_address).field_0 + 4);
    eVar4 = 2;
    if (uVar1 != 0 || uVar2 != 0) {
      if ((uVar1 != 0xffffffff) || (uVar3 = 0x27, uVar2 != 0xffffffff)) {
        uVar3 = 0x2f;
      }
      msg = (zmsg_t *)zmsg_alloc(uVar3);
      eVar4 = 1;
      if (msg != (zmsg_t *)0x0) {
        aps_frame_append_cmd_hdr((uVar1 & uVar2) == 0xffffffff,(uVar1 & uVar2) != 0xffffffff,0,0);
        zmsg_append_u8(msg,'\t');
        zmsg_append_u8(msg,req->key_seq);
        eVar4 = aps_send_cmd(msg,&req->dst_address);
        if (eVar4 != 0) {
          zmsg_free(msg);
        }
      }
    }
  }
  return eVar4;
}

