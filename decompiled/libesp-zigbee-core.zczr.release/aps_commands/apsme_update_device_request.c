/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
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
  short sVar2;
  short sVar3;
  undefined3 extraout_var;
  int *piVar4;
  zmsg_t *msg;
  int iVar5;
  zmsg_t *msg_00;
  undefined4 uVar6;
  ezb_err_t eVar7;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  eVar7 = 2;
  if (req != (apsme_update_device_req_t *)0x0) {
    _Var1 = ezb_eui64_is_invalid((ezb_eui64_s *)req);
    eVar7 = 2;
    if (CONCAT31(extraout_var,_Var1) == 0) {
      piVar4 = (int *)nwk_get_extended_address();
      if ((*piVar4 == *(int *)&req->field_0) && (piVar4[1] == *(int *)((int)&req->field_0 + 4))) {
        apsme_update_device_indication(req);
        eVar7 = 0;
      }
      else {
        msg = (zmsg_t *)zmsg_alloc(0x3c);
        eVar7 = 1;
        if (msg != (zmsg_t *)0x0) {
          aps_frame_append_cmd_hdr(0,1,1,0);
          zmsg_append_u8(msg,'\x06');
          uStack_28 = *(undefined4 *)&(req->device_address).field_0;
          uStack_24 = *(undefined4 *)((int)&(req->device_address).field_0 + 4);
          zmsg_append_bytes(msg,8,&uStack_28);
          uStack_28 = CONCAT22(uStack_28._2_2_,req->device_shortaddr);
          zmsg_append_bytes(msg,2,&uStack_28);
          zmsg_append_u8(msg,req->status);
          iVar5 = aps_secur_get_key_pair_by_addr(req);
          if (((iVar5 == 0) || ((*(ushort *)(iVar5 + 0x34) & 1) != 0)) &&
             (msg_00 = (zmsg_t *)zmsg_alloc(0x2f), msg_00 != (zmsg_t *)0x0)) {
            aps_frame_append_cmd_hdr(0,1,0,0);
            uVar6 = zmsg_get_offset(msg);
            sVar2 = zmsg_get_length(msg);
            sVar3 = zmsg_get_offset(msg);
            iVar5 = zmsg_append_bytes_from_msg(msg_00,msg,uVar6,sVar2 - sVar3);
            if ((iVar5 != 0) || (eVar7 = aps_send_cmd(msg_00,(ezb_extaddr_t *)req), eVar7 != 0)) {
              zmsg_free(msg_00);
            }
          }
          eVar7 = aps_send_cmd(msg,(ezb_extaddr_t *)req);
          if (eVar7 != 0) {
            zmsg_free(msg);
          }
        }
      }
    }
  }
  return eVar7;
}

