/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> apsme_update_device_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t apsme_update_device_request(apsme_update_device_req_t *req)

{
  short sVar1;
  short sVar2;
  int *piVar3;
  zmsg_t *msg;
  int iVar4;
  zmsg_t *msg_00;
  undefined4 uVar5;
  ezb_err_t eVar6;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  if (req == (apsme_update_device_req_t *)0x0) {
    eVar6 = 2;
    msg = (zmsg_t *)0x0;
  }
  else {
    iVar4 = *(int *)((int)&req->field_0 + 4);
    if (*(int *)&req->field_0 == 0 && iVar4 == 0) {
      msg = (zmsg_t *)0x0;
      eVar6 = 2;
    }
    else if ((*(int *)&req->field_0 == -1) && (iVar4 == -1)) {
      msg = (zmsg_t *)0x0;
      eVar6 = 2;
    }
    else {
      piVar3 = (int *)nwk_get_extended_address();
      if ((*(int *)&req->field_0 == *piVar3) && (*(int *)((int)&req->field_0 + 4) == piVar3[1])) {
        apsme_update_device_indication(req);
        return 0;
      }
      msg = (zmsg_t *)zmsg_alloc(0x3c);
      if (msg == (zmsg_t *)0x0) {
        eVar6 = 1;
      }
      else {
        aps_frame_append_cmd_hdr(0,1,0);
        uStack_28 = CONCAT31(uStack_28._1_3_,6);
        zmsg_append_bytes(msg,1,&uStack_28);
        uStack_28 = *(undefined4 *)&(req->device_address).field_0;
        uStack_24 = *(undefined4 *)((int)&(req->device_address).field_0 + 4);
        zmsg_append_bytes(msg,8,&uStack_28);
        uStack_28 = CONCAT22(uStack_28._2_2_,req->device_shortaddr);
        zmsg_append_bytes(msg,2,&uStack_28);
        uStack_28 = CONCAT31(uStack_28._1_3_,req->status);
        zmsg_append_bytes(msg,1,&uStack_28);
        iVar4 = aps_secur_get_key_pair_by_addr(req);
        if (((iVar4 == 0) || ((*(ushort *)(iVar4 + 0x34) & 1) != 0)) &&
           (msg_00 = (zmsg_t *)zmsg_alloc(0x2f), msg_00 != (zmsg_t *)0x0)) {
          aps_frame_append_cmd_hdr(0,1,0,0);
          uVar5 = zmsg_get_offset(msg);
          sVar1 = zmsg_get_length(msg);
          sVar2 = zmsg_get_offset(msg);
          iVar4 = zmsg_append_bytes_from_msg(msg_00,msg,uVar5,sVar1 - sVar2);
          if ((iVar4 != 0) || (eVar6 = aps_send_cmd(msg_00,(ezb_extaddr_t *)req), eVar6 != 0)) {
            zmsg_free(msg_00);
          }
        }
        eVar6 = aps_send_cmd(msg,(ezb_extaddr_t *)req);
        if (eVar6 == 0) {
          return 0;
        }
      }
    }
  }
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return eVar6;
}

