/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_nlme.o -> nwk_handle_leave_sent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_handle_leave_sent(zmsg_t *msg,ezb_err_t error)

{
  code *pcVar1;
  _Bool _Var2;
  short sVar3;
  int iVar4;
  int iVar5;
  undefined3 extraout_var;
  int extraout_a1;
  byte bStack_3d;
  nwk_leave_ind_t nStack_3c;
  ezb_err_t eStack_2c;
  zmsg_t *pzStack_28;
  code *pcStack_24;
  undefined1 local_20 [4];
  nwk_leave_cnf_t cnf;
  uint8_t cmd_opt;
  
  cnf.field_1._9_1_ = 0;
  sVar3 = zmsg_get_offset();
  zmsg_read_bytes(msg,sVar3 + 1,1,(undefined1 *)((int)&cnf.field_1 + 9));
  if ((cnf.field_1._9_1_ & 0x40) != 0) {
    if (error == 0x1f0) {
      error = 0;
    }
    cnf._0_4_ = 0;
    cnf.field_1._2_4_ = 0;
    local_20 = (undefined1  [4])(error & 0xff);
    cnf.field_1._7_1_ = 0;
    cnf.field_1._6_1_ =
         (byte)(((byte)cnf.field_1._9_1_ & 1) << 1) | (byte)cnf.field_1._9_1_ >> 5 & 1;
    iVar4 = nwk_frame_get_dst_extaddr(msg,&cnf);
    if (iVar4 == 0) {
      zmsg_read_bytes(msg,2,(nwk_leave_ind_t *)(local_20 + 2));
      nwk_handle_device_leave((nwk_leave_ind_t *)(local_20 + 2));
      nwk_leave_confirm((nwk_leave_cnf_t *)local_20);
    }
_L0:
    if (msg != (zmsg_t *)0x0) {
      zmsg_free(msg);
    }
    return;
  }
  iVar4 = core_globals_get();
  if (*(char *)(iVar4 + 0xac0) == '\x04') {
    nwk_do_leave_continue
              (error,(_Bool)((byte)cnf.field_1._9_1_ >> 5 & 1),(_Bool)((byte)cnf.field_1._9_1_ >> 7)
              );
    goto _L0;
  }
  pcVar1 = nwk_handle_leave;
  iVar4 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_nlme.c",0x252,
                        "nwk_handle_leave_sent",
                        "(((*core_globals_get()).nwk).ctx).state == NWK_STATE_LEAVING");
  nStack_3c.device_address.field_0.u64._2_4_ = 0;
  nStack_3c._8_4_ = 0;
  nStack_3c.device_address.field_0.u64._0_2_ = 0;
  nStack_3c.short_address = *(ushort *)(extraout_a1 + 6);
  bStack_3d = 0;
  eStack_2c = error;
  pzStack_28 = msg;
  pcStack_24 = pcVar1;
  iVar5 = nwk_is_joined();
  if ((iVar5 != 0) && (*(short *)(extraout_a1 + 2) == *(short *)(extraout_a1 + 6))) {
    iVar5 = nwk_secur_get_seclevel();
    if (((*(ushort *)(iVar4 + 0x16) & 2) != 0) != (iVar5 != 0)) goto _L0;
    iVar5 = nwk_frame_get_src_extaddr(iVar4,&nStack_3c.device_address);
    if ((iVar5 == 0) ||
       (iVar5 = nwk_address_extended_by_short
                          (*(undefined2 *)(extraout_a1 + 6),&nStack_3c.device_address), iVar5 == 0))
    {
      sVar3 = zmsg_get_offset(iVar4);
      zmsg_read_bytes(iVar4,sVar3 + 1,1,&bStack_3d);
      _Var2 = (_Bool)(bStack_3d >> 5 & 1);
      nStack_3c._10_1_ = nStack_3c._10_1_ & 0xfc | _Var2 | (bStack_3d >> 7) << 1;
      if ((bStack_3d & 0x40) == 0) {
        nwk_handle_device_leave(&nStack_3c);
        nwk_leave_indication(&nStack_3c);
      }
      else {
        _Var2 = nwk_validate_leave_request
                          (*(ezb_shortaddr_t *)(extraout_a1 + 6),
                           *(ezb_shortaddr_t *)(extraout_a1 + 4),_Var2);
        if (((CONCAT31(extraout_var,_Var2) != 0) &&
            (iVar5 = core_globals_get(), *(char *)(iVar5 + 0xac0) != '\x04')) &&
           (iVar5 = core_globals_get(), *(char *)(iVar5 + 0xac0) == '\0')) {
          nwk_do_leave('\x01',(_Bool)(SUB41(nStack_3c._8_4_,2) & 1),
                       (_Bool)((byte)((uint)nStack_3c._8_4_ >> 0x11) & 1));
        }
      }
    }
  }
  if (iVar4 == 0) {
    return;
  }
_L0:
  zmsg_free(iVar4);
  return;
}

