/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk.o -> nwk_nlde_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_nlde_data_request(nwk_nlde_data_req_t *req)

{
  uint16_t uVar1;
  int iVar2;
  _Bool _Var3;
  undefined3 extraout_var;
  uint uVar4;
  int iVar5;
  zmsg_t *pzVar6;
  uint8_t uStack_11;
  
  iVar2 = 2;
  if (req != (nwk_nlde_data_req_t *)0x0) {
    pzVar6 = req->nsdu;
    iVar2 = 2;
    if (pzVar6 != (zmsg_t *)0x0) {
      _Var3 = nwk_is_joined();
      iVar2 = 3;
      if (CONCAT31(extraout_var,_Var3) != 0) {
        zmsg_set_offset(pzVar6,0);
        if ((req->field_0xa & 4) == 0) {
          iVar2 = core_globals_get();
          uVar1 = *(uint16_t *)(iVar2 + 0x9e2);
        }
        else {
          uVar1 = req->alias_src_addr;
        }
        iVar2 = nwk_frame_write_hdr(pzVar6,uVar1,req->dst_addr,req->radius,0,
                                    *(uint *)&req->alias_src_addr >> 0x10 & 1,
                                    *(uint *)&req->alias_src_addr >> 0x11 & 1);
        if (iVar2 == 0) {
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
            nwk_fwd_send_msg(pzVar6);
          }
          else {
            iVar2 = 4;
          }
        }
      }
    }
  }
  return iVar2;
}

