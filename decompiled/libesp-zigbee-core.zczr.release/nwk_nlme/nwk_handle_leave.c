/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_handle_leave
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_handle_leave(zmsg_t *msg,nwk_rx_info_t *rx_info)

{
  _Bool _Var1;
  short sVar2;
  int iVar3;
  undefined3 extraout_var;
  byte bStack_1d;
  undefined1 auStack_1c [3];
  uint8_t cmd_opt;
  nwk_leave_ind_t ind;
  
  auStack_1c._0_2_ = rx_info->nwk_src_addr;
  stack0xffffffe6 = 0;
  ind.short_address = 0;
  ind.device_address.field_0.u64._0_2_ = 0;
  ind.device_address.field_0.u64._2_4_ = 0;
  bStack_1d = 0;
  iVar3 = nwk_is_joined();
  if ((iVar3 == 0) || (rx_info->mac_src_addr != rx_info->nwk_src_addr)) {
    if (msg == (zmsg_t *)0x0) {
      return;
    }
  }
  else {
    iVar3 = nwk_secur_get_seclevel();
    if (((ushort)(iVar3 != 0) == (msg->flags >> 1 & 1)) &&
       ((iVar3 = nwk_frame_get_src_extaddr(msg,auStack_1c + 2), iVar3 == 0 ||
        (iVar3 = nwk_address_extended_by_short(rx_info->nwk_src_addr,auStack_1c + 2), iVar3 == 0))))
    {
      sVar2 = zmsg_get_offset(msg);
      zmsg_read_bytes(msg,sVar2 + 1,1,&bStack_1d);
      _Var1 = (_Bool)(bStack_1d >> 5 & 1);
      ind.device_address.field_0.u8[4] =
           ind.device_address.field_0.u8[4] & 0xfc | _Var1 | (bStack_1d >> 7) << 1;
      if ((bStack_1d & 0x40) == 0) {
        nwk_handle_device_leave((nwk_leave_ind_t *)auStack_1c);
        nwk_leave_indication((nwk_leave_ind_t *)auStack_1c);
      }
      else {
        _Var1 = nwk_validate_leave_request(rx_info->nwk_src_addr,rx_info->nwk_dst_addr,_Var1);
        if (((CONCAT31(extraout_var,_Var1) != 0) &&
            (iVar3 = core_globals_get(), *(char *)(iVar3 + 0xac0) != '\x04')) &&
           (iVar3 = core_globals_get(), *(char *)(iVar3 + 0xac0) == '\0')) {
          nwk_do_leave('\x01',(_Bool)((byte)((uint)ind.device_address.field_0._2_4_ >> 0x10) & 1),
                       (_Bool)((byte)((uint)ind.device_address.field_0.u64._2_4_ >> 0x11) & 1));
        }
      }
    }
  }
  zmsg_free(msg);
  return;
}

