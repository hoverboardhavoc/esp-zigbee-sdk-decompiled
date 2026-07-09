/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_bind_trans_schedule_next_nmsg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool aps_bind_trans_schedule_next_nmsg
               (undefined4 param_1,undefined2 *param_2,undefined4 param_3,char *param_4)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 auStack_24 [2];
  
  local_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  auStack_24[0] = param_3;
  zmsg_get_footer(param_3,&local_40,0x1c);
  cVar3 = '\0';
  do {
    param_2 = (undefined2 *)aps_bind_table_next_dst_by_src(param_1,param_2);
    if (((param_2 == (undefined2 *)0x0) || (iVar1 = zmsg_clone(param_3), iVar1 == 0)) ||
       (iVar2 = zmsg_add_footer(auStack_24,4), iVar2 != 0)) goto _L0;
    *(ushort *)(iVar1 + 0x16) = *(ushort *)(iVar1 + 0x16) | 0x20;
    if ((*(byte *)((int)param_2 + 5) & 1) == 0) {
      uStack_3c = CONCAT31(uStack_3c._1_3_,3);
      iVar2 = nwk_address_extended_by_ref(*param_2,(int)&uStack_3c + 2);
      if (iVar2 != 0) {
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_main.c",0x127,
                      "aps_bind_trans_schedule_next_nmsg",
                      "(nwk_address_extended_by_ref(dst->extaddr.addr_ref, &req.dst_addr.u.extended_addr)) == 0"
                     );
_L0:
        if (cVar3 != '\0') {
          *param_4 = cVar3;
        }
        return cVar3 == '\0';
      }
      uStack_34 = CONCAT13(*(undefined1 *)(param_2 + 1),(undefined3)uStack_34);
    }
    else {
      uStack_3c = CONCAT22(*param_2,1);
      uStack_38 = 0xffff;
      uStack_34 = (uStack_34 >> 0x10 & 0xff) << 0x10;
    }
    local_40 = iVar1;
    iVar1 = aps_apsde_data_request(&local_40);
    if (iVar1 == 0) {
      cVar3 = cVar3 + '\x01';
    }
  } while( true );
}

