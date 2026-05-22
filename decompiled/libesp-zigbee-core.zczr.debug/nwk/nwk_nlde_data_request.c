/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_nlde_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_nlde_data_request(nwk_nlde_data_req_t *req)

{
  uint16_t uVar1;
  _Bool _Var2;
  undefined3 extraout_var;
  int iVar3;
  uint uVar4;
  int iVar5;
  zmsg_t *pzVar6;
  uint8_t uStack_11;
  
  if (req == (nwk_nlde_data_req_t *)0x0) {
    iVar3 = 2;
  }
  else {
    pzVar6 = req->nsdu;
    if (pzVar6 == (zmsg_t *)0x0) {
      iVar3 = 2;
    }
    else {
      _Var2 = nwk_is_joined();
      if (CONCAT31(extraout_var,_Var2) == 0) {
        iVar3 = 3;
      }
      else {
        zmsg_set_offset(pzVar6,0);
        if ((req->field_0xa & 4) == 0) {
          iVar3 = core_globals_get();
          uVar1 = *(uint16_t *)(iVar3 + 0x9e2);
        }
        else {
          uVar1 = req->alias_src_addr;
        }
        iVar3 = nwk_frame_write_hdr(pzVar6,uVar1,req->dst_addr,req->radius,0,
                                    *(uint *)&req->alias_src_addr >> 0x10 & 1,
                                    *(uint *)&req->alias_src_addr >> 0x11 & 1);
        if (iVar3 == 0) {
          uVar4 = zmsg_get_length(pzVar6);
          if (uVar4 < 0x71) {
            if ((req->field_0xa & 4) == 0) {
              iVar5 = core_globals_get();
              uStack_11 = *(uint8_t *)(iVar5 + 0x9d9);
              *(uint8_t *)(iVar5 + 0x9d9) = uStack_11 + '\x01';
            }
            else {
              uStack_11 = req->alias_seq_num;
            }
            zmsg_write_bytes(pzVar6,7,1,&uStack_11);
            nwk_fwd_send_msg_delayed(pzVar6,0);
          }
          else {
            iVar3 = 4;
          }
        }
      }
    }
  }
  return iVar3;
}

