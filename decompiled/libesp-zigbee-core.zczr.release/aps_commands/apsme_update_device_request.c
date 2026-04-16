/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_commands.o -> apsme_update_device_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t apsme_update_device_request(apsme_update_device_req_t *req)

{
  _Bool _Var1;
  undefined3 extraout_var;
  int *piVar2;
  zmsg_t *msg;
  undefined1 nwk_secured;
  ezb_err_t eVar3;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  eVar3 = 2;
  if (req != (apsme_update_device_req_t *)0x0) {
    _Var1 = ezb_eui64_is_invalid((ezb_eui64_s *)req);
    eVar3 = 2;
    if (CONCAT31(extraout_var,_Var1) == 0) {
      piVar2 = (int *)nwk_get_extended_address();
      if ((*piVar2 == *(int *)&req->field_0) && (piVar2[1] == *(int *)((int)&req->field_0 + 4))) {
        apsme_update_device_indication(req);
        eVar3 = 0;
      }
      else {
        msg = (zmsg_t *)zmsg_alloc(0x3c);
        eVar3 = 1;
        if (msg != (zmsg_t *)0x0) {
          aps_frame_append_cmd_hdr(0,1,1,0);
          zmsg_append_u8(msg,'\x06');
          uStack_18 = *(undefined4 *)&(req->device_address).field_0;
          uStack_14 = *(undefined4 *)((int)&(req->device_address).field_0 + 4);
          zmsg_append_bytes(msg,8,&uStack_18);
          nwk_secured = SUB41(&uStack_18,0);
          uStack_18 = CONCAT22(uStack_18._2_2_,req->device_shortaddr);
          zmsg_append_bytes(msg,2);
          zmsg_append_u8(msg,req->status);
          eVar3 = aps_send_cmd(msg,(ezb_extaddr_t *)req,(_Bool)nwk_secured);
          if (eVar3 != 0) {
            zmsg_free(msg);
          }
        }
      }
    }
  }
  return eVar3;
}

