/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> apsme_remove_device_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t apsme_remove_device_request(apsme_remove_device_req_t *req)

{
  int iVar1;
  int iVar2;
  zmsg_t *msg;
  ezb_err_t eVar3;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (req == (apsme_remove_device_req_t *)0x0) {
    eVar3 = 2;
    msg = (zmsg_t *)0x0;
  }
  else {
    iVar1 = *(int *)&(req->parent_address).field_0;
    iVar2 = *(int *)((int)&(req->parent_address).field_0 + 4);
    if (iVar1 == 0 && iVar2 == 0) {
      msg = (zmsg_t *)0x0;
      eVar3 = 2;
    }
    else if ((iVar1 == -1) && (iVar2 == -1)) {
      msg = (zmsg_t *)0x0;
      eVar3 = 2;
    }
    else {
      iVar1 = *(int *)&(req->target_address).field_0;
      iVar2 = *(int *)((int)&(req->target_address).field_0 + 4);
      if (iVar1 == 0 && iVar2 == 0) {
        msg = (zmsg_t *)0x0;
        eVar3 = 2;
      }
      else if ((iVar1 == -1) && (iVar2 == -1)) {
        msg = (zmsg_t *)0x0;
        eVar3 = 2;
      }
      else {
        msg = (zmsg_t *)zmsg_alloc(0x3c);
        if (msg == (zmsg_t *)0x0) {
          eVar3 = 1;
        }
        else {
          aps_frame_append_cmd_hdr(0,1,0);
          uStack_18 = CONCAT31(uStack_18._1_3_,7);
          zmsg_append_bytes(msg,1,&uStack_18);
          uStack_18 = *(undefined4 *)&(req->target_address).field_0;
          uStack_14 = *(undefined4 *)((int)&(req->target_address).field_0 + 4);
          zmsg_append_bytes(msg,8,&uStack_18);
          eVar3 = aps_send_cmd(msg,&req->parent_address,true);
          if (eVar3 == 0) {
            return 0;
          }
        }
      }
    }
  }
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return eVar3;
}

