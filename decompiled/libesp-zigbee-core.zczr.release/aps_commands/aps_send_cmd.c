/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> aps_commands.o -> aps_send_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_send_cmd(zmsg_t *msg,ezb_extaddr_t *dst_addr)

{
  byte bVar1;
  uint uVar2;
  ezb_err_t eVar3;
  int iVar4;
  byte bStack_2f;
  undefined2 uStack_2e;
  uint8_t fcf;
  zmsg_t *pzStack_2c;
  ezb_shortaddr_t dst_shortaddr;
  aps_apsde_data_req_t aps_req;
  
  uVar2 = zmsg_get_length();
  if (0x5a < uVar2) {
    __assert_func(0,0,0,0);
  }
  memset(&aps_req,0,0x18);
  pzStack_2c = msg;
  zmsg_read_u8(msg,0,&bStack_2f);
  bVar1 = aps_req.radius & 0xfc;
  aps_req.radius = bStack_2f >> 5 & 2 | bStack_2f >> 5 & 1 | bVar1;
  if ((*(int *)&dst_addr->field_0 == -1) && (*(int *)((int)&dst_addr->field_0 + 4) == -1)) {
    uStack_2e = 0xfffd;
    aps_req.radius = bVar1;
  }
  else {
    iVar4 = nwk_address_short_by_extended(dst_addr,&uStack_2e);
    if (iVar4 != 0) {
      return iVar4;
    }
  }
  zmsg_add_footer(msg,&stack0xffffffd4,0x1c);
  if ((aps_req.radius & 2) == 0) {
    eVar3 = aps_send_frame(&stack0xffffffd4);
  }
  else {
    eVar3 = aps_retrans_send_msg(uStack_2e,0x5a,&stack0xffffffd4);
  }
  return eVar3;
}

