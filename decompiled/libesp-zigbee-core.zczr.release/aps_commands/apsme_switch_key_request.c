/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  undefined1 nwk_secured;
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
        nwk_secured = (uVar1 & uVar2) != 0xffffffff;
        aps_frame_append_cmd_hdr((uVar1 & uVar2) == 0xffffffff,0,0);
        zmsg_append_u8(msg,'\t');
        zmsg_append_u8(msg,req->key_seq);
        eVar4 = aps_send_cmd(msg,&req->dst_address,(_Bool)nwk_secured);
        if (eVar4 != 0) {
          zmsg_free(msg);
        }
      }
    }
  }
  return eVar4;
}

