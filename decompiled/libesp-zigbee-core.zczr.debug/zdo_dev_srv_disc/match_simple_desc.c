/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> match_simple_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t match_simple_desc(uint16_t profile_id,uint16_t *in_clusters,uint8_t num_of_in_clusters,
                         uint16_t *out_clusters,uint8_t num_of_out_clusters,uint8_t *match_list)

{
  byte list_len;
  uint8_t list_len_00;
  uint8_t *unaff_s0;
  _Bool _Var1;
  undefined2 in_register_0000202a;
  uint16_t *cluster_list;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint unaff_s2;
  
  if (match_list != (uint8_t *)0x0) {
    unaff_s0 = (uint8_t *)0x0;
    unaff_s2 = 0;
    while (unaff_s0 = (uint8_t *)af_get_next_simple_desc(unaff_s0), unaff_s0 != (uint8_t *)0x0) {
      cluster_list = *(uint16_t **)(unaff_s0 + 0xc);
      list_len = unaff_s0[7];
      list_len_00 = unaff_s0[8];
      if ((((uint)*(ushort *)(unaff_s0 + 2) == CONCAT22(in_register_0000202a,profile_id)) ||
          (CONCAT22(in_register_0000202a,profile_id) == 0xffff)) &&
         ((_Var1 = clusters_is_on_list(cluster_list,list_len,in_clusters,num_of_in_clusters),
          CONCAT31(extraout_var,_Var1) != 0 ||
          (_Var1 = clusters_is_on_list(cluster_list + list_len,list_len_00,out_clusters,
                                       num_of_out_clusters), CONCAT31(extraout_var_00,_Var1) != 0)))
         ) {
_L0:
        match_list[unaff_s2] = *unaff_s0;
        unaff_s2 = unaff_s2 + 1 & 0xff;
      }
    }
    return (uint8_t)unaff_s2;
  }
  __assert_func("//build/esp-zigbee/src/core/zdo/zdo_dev_srv_disc.c",0x3ea,"match_simple_desc",
                "match_list");
  goto _L0;
}

